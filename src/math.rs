#[repr(C)]
pub struct Vector2<T: Copy> {
    pub x: T,
    pub y: T,
}

impl<T: Copy> Clone for Vector2<T> {
    fn clone(&self) -> Self {
        return Vector2 {
            x: self.x,
            y: self.y,
        };
    }
}

#[repr(C)]
pub struct Vector4<T: Copy> {
    pub x: T,
    pub y: T,
    pub z: T,
    pub w: T,
}

impl<T: Copy> Clone for Vector4<T> {
    fn clone(&self) -> Self {
        return Vector4 { x: self.x, y: self.y, z: self.z, w: self.w };
    }
}

#[repr(C)]
pub struct Matrix4<T: Copy> {
    matrix: [[T; 4]; 4]
}

impl <T: Copy> Matrix4<T> {
    pub fn new(a: T, b: T) -> Matrix4<T> {
        let mut matrix = [[a; 4]; 4];
        matrix[0][0] = b;
        matrix[1][1] = b;
        matrix[2][2] = b;
        matrix[3][3] = b;
        
        return Matrix4 { matrix };
    }
    
    pub fn as_ptr(&self) -> *const T {
        return &(self.matrix[0][0]);
    }
}

pub fn orthographic(left: f32, right: f32, top: f32, bottom: f32, far: f32, near: f32) -> Matrix4<f32> {
    let mut matrix = Matrix4::<f32>::new(0.0, 1.0);
    
    matrix.matrix[0][0] = 2.0 / (right - left);
    matrix.matrix[1][1] = 2.0 / (top - bottom);
    matrix.matrix[2][2] = -2.0 / (far - near);
    
    matrix.matrix[0][3] = -((right + left) / (right - left));
    matrix.matrix[1][3] = -((top + bottom) / (top - bottom));
    matrix.matrix[2][3] = -((far + near) / (far - near));
    
    return matrix;
}