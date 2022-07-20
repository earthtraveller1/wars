pub struct Game {
    window: crate::Window,
}

impl Game {
    pub fn new() -> Game {
        let mut window = crate::Window::new(1280, 720, "Wars");
        
        window.show();
        
        return Game { window };
    }
    
    pub fn is_running(&self) -> bool {
        return self.window.is_open();
    }
    
    pub fn update(&mut self) {
        self.window.update();
    }
}