use stb::image::*;
use crate::math;

// I will only add the types that I will be using
enum OpenGLType {
    Float,
    Short,
}

struct VertexArray {
    handle: u32,
}

impl VertexArray {
    fn new() -> VertexArray {
        let mut handle = 0;

        unsafe {
            gl::GenVertexArrays(1, &mut handle);
        }

        return VertexArray { handle: handle };
    }

    fn bind(&self) {
        unsafe {
            gl::BindVertexArray(self.handle);
        }
    }

    fn unbind() {
        unsafe {
            gl::BindVertexArray(0);
        }
    }

    fn create_vertex_attribute(
        &self,
        index: u32,
        size: u8,
        attribute_type: OpenGLType,
        stride: i32,
        offset: usize,
    ) {
        unsafe {
            self.bind();
            gl::VertexAttribPointer(
                index,
                size.try_into().unwrap(),
                match attribute_type {
                    OpenGLType::Float => gl::FLOAT,
                    OpenGLType::Short => gl::SHORT,
                },
                gl::FALSE,
                stride,
                offset as *const std::ffi::c_void,
            );
            gl::EnableVertexAttribArray(index);
        }
    }
}

impl Drop for VertexArray {
    fn drop(&mut self) {
        unsafe {
            gl::DeleteVertexArrays(1, &mut self.handle);
        }
    }
}

enum BufferType {
    Vertex,
    Index,
}

// Once again, only included the ones that I will use.
enum BufferUsage {
    Static,
    Dynamic,
}

struct Buffer {
    handle: u32,
    buffer_type: u32,
}

impl Buffer {
    fn new<T>(data: Vec<T>, buffer_type: BufferType, buffer_usage: BufferUsage) -> Buffer {
        let mut handle = 0;
        let buffer_type = match buffer_type {
            BufferType::Vertex => gl::ARRAY_BUFFER,
            BufferType::Index => gl::ELEMENT_ARRAY_BUFFER,
        };

        unsafe {
            gl::GenBuffers(1, &mut handle);
            gl::BindBuffer(buffer_type, handle);
            gl::BufferData(
                buffer_type,
                (data.len() * std::mem::size_of::<T>()).try_into().unwrap(),
                data.as_ptr() as *const std::ffi::c_void,
                match buffer_usage {
                    BufferUsage::Static => gl::STATIC_DRAW,
                    BufferUsage::Dynamic => gl::DYNAMIC_DRAW,
                },
            );

            gl::BindBuffer(buffer_type, 0);
        }

        return Buffer {
            handle,
            buffer_type,
        };
    }

    /// Creates a new empty buffer
    fn new_empty(size: isize, buffer_type: BufferType, buffer_usage: BufferUsage) -> Buffer {
        let mut handle = 0;
        let buffer_type = match buffer_type {
            BufferType::Vertex => gl::ARRAY_BUFFER,
            BufferType::Index => gl::ELEMENT_ARRAY_BUFFER,
        };

        unsafe {
            gl::GenBuffers(1, &mut handle);
            gl::BindBuffer(buffer_type, handle);
            gl::BufferData(
                buffer_type,
                size,
                std::ptr::null(),
                match buffer_usage {
                    BufferUsage::Static => gl::STATIC_DRAW,
                    BufferUsage::Dynamic => gl::DYNAMIC_DRAW,
                },
            );

            gl::BindBuffer(buffer_type, 0);
        }

        return Buffer {
            handle,
            buffer_type,
        };
    }

    fn bind(&self) {
        unsafe {
            gl::BindBuffer(self.buffer_type, self.handle);
        }
    }

    fn unbind(&self) {
        unsafe {
            gl::BindBuffer(self.buffer_type, 0);
        }
    }

    fn set_sub_data<T>(&self, offset: isize, data: &Vec<T>) {
        self.bind();

        unsafe {
            gl::BufferSubData(
                self.buffer_type,
                offset,
                (data.len() * std::mem::size_of::<T>()).try_into().unwrap(),
                data.as_ptr() as *const std::ffi::c_void,
            );
        }

        self.unbind();
    }
}

impl Drop for Buffer {
    fn drop(&mut self) {
        self.unbind();

        unsafe {
            gl::DeleteBuffers(1, &self.handle);
        }
    }
}

fn create_shader(source_path: &str, shader_type: u32) -> u32 {
    let source = std::fs::read_to_string(source_path);
    let source = match source {
        Ok(source) => source,
        Err(e) => {
            eprintln!(
                "[ERROR]: Failed to load file {}: {}",
                source_path,
                e.to_string()
            );
            "".to_string()
        }
    };

    let shader;

    unsafe {
        shader = gl::CreateShader(shader_type);
        let source = std::ffi::CString::new(source.as_bytes()).unwrap();
        gl::ShaderSource(shader, 1, &source.as_ptr(), std::ptr::null());
        gl::CompileShader(shader);
    }

    let mut success = 0;

    unsafe {
        gl::GetShaderiv(shader, gl::COMPILE_STATUS, &mut success);
    }

    if success != gl::TRUE.into() {
        let mut error_log: Vec<u8> = Vec::with_capacity(512);
        unsafe {
            gl::GetShaderInfoLog(
                shader, 
                512, 
                std::ptr::null::<i32>() as *mut i32, 
                error_log.as_mut_ptr() as *mut i8
            );

            eprintln!(
                "[ERROR]: Failed to compile shader {}:\n{}\n\n",
                source_path,
                String::from_utf8(error_log).unwrap()
            );
        }
    }

    return shader;
}

struct ShaderProgram {
    handle: u32,
}

impl ShaderProgram {
    fn new(vertex_source_path: &str, fragment_source_path: &str) -> ShaderProgram {
        let vertex = create_shader(vertex_source_path, gl::VERTEX_SHADER);
        let fragment = create_shader(fragment_source_path, gl::FRAGMENT_SHADER);

        let mut handle = 0;

        unsafe {
            handle = gl::CreateProgram();
            gl::AttachShader(handle, vertex);
            gl::AttachShader(handle, fragment);
            gl::LinkProgram(handle);

            // We can delete the shaders once they're linked to the program.
            gl::DeleteShader(vertex);
            gl::DeleteShader(fragment);
        }

        let mut success = 0;

        unsafe {
            gl::GetProgramiv(handle, gl::LINK_STATUS, &mut success);
        }

        if success != gl::TRUE.into() {
            let error_log_layout = std::alloc::Layout::array::<i8>(512).unwrap();

            unsafe {
                let error_log = std::alloc::alloc(error_log_layout);
                gl::GetProgramInfoLog(
                    handle,
                    512,
                    std::ptr::null::<i32>() as *mut i32,
                    error_log as *mut i8,
                );

                eprintln!(
                    "[ERROR]: Failed to link a shader program:\n{}\n\n",
                    String::from_raw_parts(error_log, 512, 512)
                );

                std::alloc::dealloc(error_log, error_log_layout);
            }
        }

        return ShaderProgram { handle: handle };
    }

    fn use_program(&self) {
        unsafe {
            gl::UseProgram(self.handle);
        }
    }

    // I'll add the uniform functions when I need them.
}

impl Drop for ShaderProgram {
    fn drop(&mut self) {
        unsafe {
            gl::UseProgram(0);
            gl::DeleteProgram(self.handle);
        }
    }
}

struct Texture {
    handle: u32,
}

impl Texture {
    fn new(image_path: &str) -> Texture {
        let mut handle: u32 = 0;

        unsafe {
            gl::GenTextures(1, &mut handle);
            gl::BindTexture(gl::TEXTURE_2D, handle);

            gl::TexParameteri(
                gl::TEXTURE_2D,
                gl::TEXTURE_MIN_FILTER,
                gl::LINEAR.try_into().unwrap(),
            );
            gl::TexParameteri(
                gl::TEXTURE_2D,
                gl::TEXTURE_MAG_FILTER,
                gl::LINEAR.try_into().unwrap(),
            );

            gl::TexParameteri(
                gl::TEXTURE_2D,
                gl::TEXTURE_WRAP_S,
                gl::CLAMP_TO_EDGE.try_into().unwrap(),
            );
            gl::TexParameteri(
                gl::TEXTURE_2D,
                gl::TEXTURE_WRAP_T,
                gl::CLAMP_TO_EDGE.try_into().unwrap(),
            );
        }

        let mut image_file = std::fs::File::open(image_path).unwrap();
        let (image_info, image_data) =
            stbi_load_from_reader(&mut image_file, Channels::Default).unwrap();

        let image_format = match image_info.components {
            1 => gl::RED,
            2 => gl::RG,
            3 => gl::RGB,
            4 => gl::RGBA,
            _ => gl::RGB,
        };

        unsafe {
            gl::TexImage2D(
                gl::TEXTURE_2D,
                0,
                image_format.try_into().unwrap(),
                image_info.width,
                image_info.height,
                0,
                image_format,
                gl::UNSIGNED_BYTE,
                image_data.into_vec().as_ptr() as *const std::ffi::c_void,
            );
            gl::GenerateMipmap(gl::TEXTURE_2D);

            gl::BindTexture(gl::TEXTURE_2D, 0);
        }

        return Texture { handle };
    }

    fn bind(&self) {
        unsafe {
            gl::BindTexture(gl::TEXTURE_2D, self.handle);
        }
    }

    fn unbind() {
        unsafe {
            gl::BindTexture(gl::TEXTURE_2D, 0);
        }
    }

    fn set_active_texture(texture_unit: u32) {
        unsafe { gl::ActiveTexture(gl::TEXTURE0 + texture_unit) }
    }
}

impl Drop for Texture {
    fn drop(&mut self) {
        Texture::unbind();

        unsafe {
            gl::DeleteTextures(1, &self.handle);
        }
    }
}
#[repr(C)]
struct Vertex2D {
    position: math::Vector2<f32>,
    uv: math::Vector2<f32>,
    color: math::Vector4<f32>,
    texture: i16,
}

pub struct Renderer2D {
    vertex_array: VertexArray,
    vertex_buffer: Buffer,
    index_buffer: Buffer,

    vertices: Vec<Vertex2D>,
    quads_to_draw: u32,
    max_quads: u32,

    shader_program: ShaderProgram,
}

impl Renderer2D {
    pub fn new(
        max_quads: usize,
        vertex_shader_path: &str,
        fragment_shader_path: &str,
    ) -> Renderer2D {
        let shader_program = ShaderProgram::new(vertex_shader_path, fragment_shader_path);

        let vertex_array = VertexArray::new();
        vertex_array.bind();

        let vertices = Vec::with_capacity(max_quads * 4);

        let vertex_buffer = Buffer::new_empty(
            (max_quads * std::mem::size_of::<Vertex2D>() * 4)
                .try_into()
                .unwrap(),
            BufferType::Vertex,
            BufferUsage::Dynamic,
        );
        vertex_buffer.bind();

        let mut indices = Vec::with_capacity(max_quads * 6);

        for i in 0..max_quads {
            indices.push(i + 0);
            indices.push(i + 1);
            indices.push(i + 2);
            indices.push(i + 0);
            indices.push(i + 3);
            indices.push(i + 2);
        }

        let index_buffer = Buffer::new(indices, BufferType::Index, BufferUsage::Static);
        index_buffer.bind();

        vertex_array.create_vertex_attribute(
            0,
            2,
            OpenGLType::Float,
            std::mem::size_of::<Vertex2D>().try_into().unwrap(),
            0,
        );

        vertex_array.create_vertex_attribute(
            1,
            2,
            OpenGLType::Float,
            std::mem::size_of::<Vertex2D>().try_into().unwrap(),
            2 * std::mem::size_of::<f32>(),
        );

        vertex_array.create_vertex_attribute(
            2,
            4,
            OpenGLType::Float,
            std::mem::size_of::<Vertex2D>().try_into().unwrap(),
            4 * std::mem::size_of::<f32>(),
        );

        vertex_array.create_vertex_attribute(
            3,
            1,
            OpenGLType::Short,
            std::mem::size_of::<Vertex2D>().try_into().unwrap(),
            8 * std::mem::size_of::<f32>(),
        );

        return Renderer2D {
            vertex_array,
            vertex_buffer,
            index_buffer,
            vertices,
            quads_to_draw: 0,
            max_quads: max_quads.try_into().unwrap(),
            shader_program,
        };
    }

    pub fn begin(&mut self) {
        self.quads_to_draw = 0;
        self.vertices.clear();
    }

    pub fn draw_colored_quad(
        &mut self,
        position: math::Vector2<f32>,
        size: math::Vector2<f32>,
        color: math::Vector4<f32>,
    ) {
        self.quads_to_draw += 1;

        // If the client made more draw calls than what was allocated, then do
        // nothing.
        if self.quads_to_draw > self.max_quads {
            self.quads_to_draw -= 1;
            return;
        }

        use math::Vector2;

        let vertex = Vertex2D {
            position: Vector2::<f32> {
                x: position.x + size.x,
                y: position.y,
            },
            uv: Vector2::<f32> { x: 1.0, y: 0.0 },
            color: color.clone(),
            texture: -1,
        };
        self.vertices.push(vertex);

        let vertex = Vertex2D {
            position: Vector2::<f32> {
                x: position.x + size.x,
                y: position.y + size.y,
            },
            uv: Vector2::<f32> { x: 1.0, y: 1.0 },
            color: color.clone(),
            texture: -1,
        };
        self.vertices.push(vertex);

        let vertex = Vertex2D {
            position: Vector2::<f32> {
                x: position.x,
                y: position.y + size.y,
            },
            uv: Vector2::<f32> { x: 0.0, y: 1.0 },
            color: color.clone(),
            texture: -1,
        };
        self.vertices.push(vertex);

        let vertex = Vertex2D {
            position,
            uv: Vector2::<f32> { x: 0.0, y: 0.0 },
            color: color,
            texture: -1,
        };
        self.vertices.push(vertex);
    }

    pub fn end(&self) {
        self.vertex_array.bind();
        self.vertex_buffer.set_sub_data(0, &self.vertices);
        self.index_buffer.bind();
        
        let quad_count: i32 = self.quads_to_draw.try_into().unwrap();
        
        self.shader_program.use_program();
        
        unsafe {
            gl::DrawElements(
                gl::TRIANGLES,
                quad_count * 6,
                gl::UNSIGNED_INT,
                std::ptr::null(),
            );
        }
    }
}
