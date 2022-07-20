use wars::Window;

fn main() {
    let mut window = Window::new(1280, 720, "Wars");
    
    window.show();
    
    while window.is_open() {
        window.update();
    }
}
