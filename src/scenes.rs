use crate::{
    graphics::Renderer2D,
    math::{Vector2, Vector4},
    Scene,
};

pub struct DummyScene {
    renderer: Renderer2D,
}

impl DummyScene {
    pub fn new() -> DummyScene {
        let renderer = Renderer2D::new(2, "assets/shaders/dummy.vs", "assets/shaders/dummy.fs");

        return DummyScene { renderer };
    }
}

impl Scene for DummyScene {
    fn update(&mut self) {
        //println!("bozo!");
    }

    fn render(&mut self) {
        self.renderer.begin();

        self.renderer.draw_colored_quad(
            Vector2 { x: 0.0, y: 0.5 },
            Vector2 { x: 0.5, y: 0.5 },
            Vector4 {
                x: 1.0,
                y: 1.0,
                z: 1.0,
                w: 1.0,
            },
        );
        
        self.renderer.end();
    }
}
