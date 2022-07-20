use std::sync::mpsc::Receiver;

use glfw::Context;

struct Window {
    glfw: glfw::Glfw,
    window: glfw::Window,
    _events: Receiver<(f64, glfw::WindowEvent)>
}

impl Window {
    fn new(width: u32, height: u32, title: &str) -> Window {
        let mut glfw = glfw::init(glfw::FAIL_ON_ERRORS)
            .expect("Failed to initialize GLFW!");
            
        glfw.window_hint(glfw::WindowHint::ContextVersion(3, 3));
        glfw.window_hint(glfw::WindowHint::OpenGlProfile(glfw::OpenGlProfileHint::Core));
        glfw.window_hint(glfw::WindowHint::Visible(false));
        
        let (mut window, events) = glfw.create_window(width, height, title, glfw::WindowMode::Windowed)
            .expect("Failed to create the Window!");
        
        window.make_current();
        window.set_key_polling(true);
        
        glfw.with_primary_monitor(|_, m| {
            let video_mode = m.unwrap()
                .get_video_mode()
                .unwrap();
            
            let new_x: u32 = (video_mode.width - width) / 2;
            let new_y: u32 = (video_mode.height - height) / 2;
            
            window.set_pos(new_x.try_into().unwrap(), new_y.try_into().unwrap());
        });
        
        return Window { glfw, window, _events: events };
    }
    
    fn show(&mut self) {
        self.window.show();
    }
    
    fn is_open(&self) -> bool {
        return !(self.window.should_close());
    }
    
    fn update(&mut self) {
        self.window.swap_buffers();
        self.glfw.poll_events();
    }
    
    fn _is_key_down(&self, key: glfw::Key) -> bool {
        let action = self.window.get_key(key);
        return action == glfw::Action::Press || action == glfw::Action::Repeat;
    }
    
    fn _is_mouse_button_down(&self, button: glfw::MouseButton) -> bool {
        let action = self.window.get_mouse_button(button);
        return action == glfw::Action::Press || action == glfw::Action::Repeat;
    }
}

pub struct Game {
    window: Window,
}

impl Game {
    pub fn new() -> Game {
        let mut window = Window::new(1280, 720, "Wars");
        
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