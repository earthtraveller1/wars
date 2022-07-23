use crate::{graphics::Renderer2D, math::Vector2, Scene};

pub struct DummyScene {
    renderer: Renderer2D,
}

impl DummyScene {
    pub fn _new() -> DummyScene {
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

        self.renderer.draw_textured_quad(
            &Vector2 { x: -2.0, y: -2.0 },
            &Vector2 { x: 4.0, y: 4.0 },
            0.0,
        );
        self.renderer.draw_textured_quad(
            &Vector2 { x: 2.0, y: 2.0 },
            &Vector2 { x: 4.0, y: 4.0 },
            1.0,
        );

        self.renderer.end();
    }
}

pub struct MenuScene {
    renderer: Renderer2D,
}

impl MenuScene {
    pub fn new() -> MenuScene {
        let mut renderer = Renderer2D::new(
            3,
            "assets/shaders/2d_renderer_basic.vs",
            "assets/shaders/2d_renderer_basic.fs",
        );

        renderer.load_texture("assets/textures/backgrounds/main_menu_background.png", 0);
        renderer.load_texture("assets/textures/ui/play_button.png", 1);
        renderer.load_texture("assets/textures/ui/other_button.png", 2);

        return MenuScene { renderer: renderer };
    }
}

impl Scene for MenuScene {
    fn update(&mut self) {}

    fn render(&mut self) {
        self.renderer.begin();

        self.renderer.draw_textured_quad(
            &Vector2 { x: 0.0, y: 0.0 },
            &Vector2 { x: 16.0, y: 9.0 },
            0.0,
        );
        
        self.renderer.draw_textured_quad(
            &Vector2 { x: -5.4, y: -0.25 }, 
            &Vector2 { x: 3.0, y: 1.5 },
            1.0
        );
        
        self.renderer.draw_textured_quad(
            &Vector2 { x: -3.9, y: -2.25 }, 
            &Vector2 { x: 6.0, y: 1.5 },
            2.0
        );

        self.renderer.end();
    }
}
