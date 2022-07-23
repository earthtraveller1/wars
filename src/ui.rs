pub struct ButtonChecker {
    mouse_x: f64,
    mouse_y: f64,
}

impl ButtonChecker {
    pub fn new() -> ButtonChecker {
        ButtonChecker {
            mouse_x: 0.0,
            mouse_y: 0.0,
        }
    }

    pub fn update_mouse_position(&mut self, x: f64, y: f64) {
        self.mouse_x = x;
        self.mouse_y = y;
        
        println!("Mouse is at {} {}", self.mouse_x, self.mouse_y);
    }

    pub fn is_button_hovered(&self, x: f64, y: f64, width: f64, height: f64) -> bool {
        let (x2, y2) = (width / 2.0 + x, height / 2.0 + y);
        
        println!("Aspect ratio is {}", width / height);

        self.mouse_x > x && self.mouse_x < x2 && self.mouse_y > y && self.mouse_y < y2
    }
}
