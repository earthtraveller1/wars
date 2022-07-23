pub struct ButtonChecker {
    window_width: f64,
    window_height: f64,

    mouse_x: f64,
    mouse_y: f64,
}

impl ButtonChecker {
    pub fn new(window_width: f64, window_height: f64) -> ButtonChecker {
        ButtonChecker {
            window_width,
            window_height,

            mouse_x: 0.0,
            mouse_y: 0.0,
        }
    }

    fn to_window_coords(&self, x: f64, y: f64) -> (f64, f64) {
        (
            (x / 8.0) * self.window_width + (self.window_width / 2.0),
            self.window_height - ((y / 4.5) * self.window_height + (self.window_height / 2.0)),
        )
    }

    pub fn update_mouse_position(&mut self, x: f64, y: f64) {
        self.mouse_x = x;
        self.mouse_y = y;
    }

    pub fn is_button_hovered(&self, x: f64, y: f64, width: f64, height: f64) -> bool {
        let (x, y) = self.to_window_coords(x - width / 2.0, height / 2.0);
        let (width, height) = self.to_window_coords(width, height);
        let (x2, y2) = (width + x, height + y);

        self.mouse_x > x && self.mouse_x < x2 && self.mouse_y > y && self.mouse_y < y2
    }
}
