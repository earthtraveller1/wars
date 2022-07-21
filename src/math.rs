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