use std::sync::mpsc::Receiver;

use glfw::Context;

pub struct Window {
    glfw: glfw::Glfw,
    window: glfw::Window,
    _events: Receiver<(f64, glfw::WindowEvent)>
}

impl Window {
    pub fn new(width: u16, height: u16, title: &str) -> Window {
        let mut glfw = glfw::init(glfw::FAIL_ON_ERRORS)
            .expect("Failed to initialize GLFW!");
            
        glfw.window_hint(glfw::WindowHint::ContextVersion(3, 3));
        glfw.window_hint(glfw::WindowHint::OpenGlProfile(glfw::OpenGlProfileHint::Core));
        glfw.window_hint(glfw::WindowHint::Visible(false));
        
        let (mut window, events) = glfw.create_window(width.into(), height.into(), title, glfw::WindowMode::Windowed)
            .expect("Failed to create the Window!");
        
        window.make_current();
        window.set_key_polling(true);
        
        return Window { glfw, window, _events: events };
    }
    
    pub fn show(&mut self) {
        self.window.show();
    }
    
    pub fn is_open(&self) -> bool {
        return !(self.window.should_close());
    }
    
    pub fn update(&mut self) {
        self.window.swap_buffers();
        self.glfw.poll_events();
    }
}