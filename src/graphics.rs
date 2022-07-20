extern crate glm;

#[repr(C)]
struct Vertex {
    position: glm::Vec2,
    uv: glm::Vec2,
    color: glm::Vec4,
    texture: i16,
}

impl Clone for Vertex {
    fn clone(&self) -> Self {
        return Vertex {
            position: self.position.clone(),
            uv: self.uv.clone(),
            color: self.color.clone(),
            texture: self.texture,
        };
    }
}

unsafe fn offsetof(host: *const std::ffi::c_void, b: *const std::ffi::c_void) -> usize {
    (b as usize) - (host as usize)
}

fn create_shader(source_path: &str, shader_type: u32) {
    let source = std::fs::read_to_string(source_path);
    let source = match source {
        Ok(source) => source,
        Err(e) => {
            eprintln!("[ERROR]: Failed to load file {}: {}", source_path, e.to_string());
            "".to_string()
        }
    };
    
    let source = std::ffi::CStr::from_bytes_with_nul(source.as_bytes()).unwrap().as_ptr();
    
    unsafe {
        let shader = gl::CreateShader(shader_type);
        gl::ShaderSource(shader, 1, &source, std::ptr::null());
        gl::CompileShader(shader);
        
        let mut success = 0;
        
        gl::GetShaderiv(shader, gl::COMPILE_STATUS, &mut success);
        
        if success != gl::TRUE.into() {
            
        }
    }
}

struct Renderer {
    vao: u32,
    vbo: u32,
    ebo: u32,

    shader_program: u32,
    vertex_iterator: u32,

    vertices: Vec<Vertex>,
}

impl Renderer {
    pub fn new(max_quads: usize, vertex_shader_path: &str, fragment_shader_path: &str) {
        let mut vao = 0;
        unsafe {
            gl::GenVertexArrays(1, &mut vao);
            gl::BindVertexArray(vao);
        }

        let default_vertex = Vertex {
            position: glm::Vec2::new(0.0, 0.0),
            uv: glm::Vec2::new(0.0, 0.0),
            color: glm::Vec4::new(0.0, 0.0, 0.0, 0.0),
            texture: -1,
        };
        
        let dummy_vertex = default_vertex.clone();

        let vertices = vec![default_vertex; max_quads * 4];

        let mut vbo = 0;
        unsafe {
            gl::GenBuffers(1, &mut vbo);
            gl::BindBuffer(gl::ARRAY_BUFFER, vbo);
            gl::BufferData(
                gl::ARRAY_BUFFER,
                (std::mem::size_of::<Vertex>() * 4 * max_quads)
                    .try_into()
                    .unwrap(),
                std::ptr::null(),
                gl::DYNAMIC_DRAW,
            );
        }

        let mut indices: Vec<u32> = Vec::with_capacity(max_quads * 6);

        for i in 0..indices.len() {
            indices.push(u32::try_from(i * 6).unwrap());
            indices.push(u32::try_from(i * 6 + 1).unwrap());
            indices.push(u32::try_from(i * 6 + 2).unwrap());
            indices.push(u32::try_from(i * 6).unwrap());
            indices.push(u32::try_from(i * 6 + 3).unwrap());
            indices.push(u32::try_from(i * 6 + 2).unwrap());
        }

        let mut ebo = 0;
        unsafe {
            gl::GenBuffers(1, &mut ebo);
            gl::BindBuffer(gl::ELEMENT_ARRAY_BUFFER, ebo);
            gl::BufferData(
                gl::ELEMENT_ARRAY_BUFFER,
                (indices.len() * std::mem::size_of::<u32>())
                    .try_into()
                    .unwrap(),
                indices.as_ptr() as *mut std::ffi::c_void,
                gl::STATIC_DRAW,
            );
        }

        unsafe {
            gl::VertexAttribPointer(
                0,
                2,
                gl::FLOAT,
                gl::FALSE,
                std::mem::size_of::<Vertex>().try_into().unwrap(),
                offsetof(
                    &dummy_vertex as *const Vertex as *mut std::ffi::c_void,
                    &dummy_vertex.position as *const glm::Vec2 as *mut std::ffi::c_void,
                ) as *const std::ffi::c_void,
            );
            gl::EnableVertexAttribArray(0);
            
            gl::VertexAttribPointer(
                1,
                2,
                gl::FLOAT,
                gl::FALSE,
                std::mem::size_of::<Vertex>().try_into().unwrap(),
                offsetof(
                    &dummy_vertex as *const Vertex as *mut std::ffi::c_void,
                    &dummy_vertex.uv as *const glm::Vec2 as *mut std::ffi::c_void,
                ) as *const std::ffi::c_void,
            );
            gl::EnableVertexAttribArray(1);
            
            gl::VertexAttribPointer(
                2,
                4,
                gl::FLOAT,
                gl::FALSE,
                std::mem::size_of::<Vertex>().try_into().unwrap(),
                offsetof(
                    &dummy_vertex as *const Vertex as *mut std::ffi::c_void,
                    &dummy_vertex.color as *const glm::Vec4 as *mut std::ffi::c_void,
                ) as *const std::ffi::c_void,
            );
            gl::EnableVertexAttribArray(2);
            
            gl::VertexAttribPointer(
                3,
                1,
                gl::SHORT,
                gl::FALSE,
                std::mem::size_of::<Vertex>().try_into().unwrap(),
                offsetof(
                    &dummy_vertex as *const Vertex as *mut std::ffi::c_void,
                    &dummy_vertex.texture as *const i16 as *mut std::ffi::c_void,
                ) as *const std::ffi::c_void,
            );
            gl::EnableVertexAttribArray(0);
        }
    }
}
