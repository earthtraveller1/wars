use crate::{graphics::Renderer2D, math::Vector2, Scene};

pub struct DummyScene {
    renderer: Renderer2D,
}

impl DummyScene {
    pub fn new() -> DummyScene {
        let mut renderer = Renderer2D::new(
            2,
            "assets/shaders/2d_renderer_basic.vs",
            "assets/shaders/2d_renderer_basic.fs",
        );

        renderer.load_texture("assets/textures/can_pooper.png", 0);

        return DummyScene { renderer };
    }
}

impl Scene for DummyScene {
    fn update(&mut self) {
        //println!("bozo!");
    }

    fn render(&mut self) {
        self.renderer.begin();

        self.renderer
            .draw_textured_quad(Vector2 { x: 0.0, y: 0.0 }, Vector2 { x: 0.5, y: 0.5 }, 0);

        self.renderer.end();
    }
}
