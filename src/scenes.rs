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

        renderer.load_texture("assets/textures/props/can_pooper.png", 0);
        renderer.load_texture("assets/textures/props/rai_rai_raku_raku.png", 1);

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
            .draw_textured_quad(&Vector2 { x: -2.0, y: -2.0 }, &Vector2 { x: 4.0, y: 4.0 }, 0.0);
        self.renderer
            .draw_textured_quad(&Vector2 { x: 2.0, y: 2.0 }, &Vector2 { x: 4.0, y: 4.0 }, 1.0);

        self.renderer.end();
    }
}
