use std::{rc::Rc, cell::RefCell};

use crate::{graphics::Renderer2D, math::{Vector2, Vector4}, Scene, Window, ui::ButtonChecker};

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

        /*self.renderer.draw_textured_quad(
            &Vector2 { x: -2.0, y: -2.0 },
            &Vector2 { x: 4.0, y: 4.0 },
            0.0,
        );
        self.renderer.draw_textured_quad(
            &Vector2 { x: 2.0, y: 2.0 },
            &Vector2 { x: 4.0, y: 4.0 },
            1.0,
        );*/

        self.renderer.end();
    }
}

pub struct MenuScene {
    renderer: Renderer2D,
    window: Rc<RefCell<Window>>,
    button_handler: ButtonChecker
}

impl MenuScene {
    pub fn new(window: Rc<RefCell<Window>>) -> MenuScene {
        let mut renderer = Renderer2D::new(
            3,
            "assets/shaders/2d_renderer_basic.vs",
            "assets/shaders/2d_renderer_basic.fs",
        );

        renderer.load_texture("assets/textures/backgrounds/main_menu_background.png", 0);
        renderer.load_texture("assets/textures/ui/play_button.png", 1);
        renderer.load_texture("assets/textures/ui/other_button.png", 2);

        return MenuScene { renderer: renderer, window, button_handler: ButtonChecker::new(1280.0, 720.0) };
    }
}

impl Scene for MenuScene {
    fn update(&mut self) {
        let (mouse_x, mouse_y) = self.window.borrow().get_mouse_position();
        self.button_handler.update_mouse_position(mouse_x, mouse_y);
    }

    fn render(&mut self) {
        self.renderer.begin();

        self.renderer.draw_quad(
            &Vector2 { x: 0.0, y: 0.0 },
            &Vector2 { x: 16.0, y: 9.0 },
            &Vector4 {
                x: 1.0,
                y: 1.0,
                z: 1.0,
                w: 1.0
            },
            0.0,
        );
        
        let button_color = if self.button_handler.is_button_hovered(-5.4, -0.25, 3.0, 1.5) {
            Vector4 { x: 0.7, y: 0.7, z: 0.7, w: 1.0 }
        } else {
            Vector4 { x: 1.0, y: 1.0, z: 1.0, w: 1.0 }
        };
        
        self.renderer.draw_quad(
            &Vector2 { x: -5.4, y: -0.25 }, 
            &Vector2 { x: 3.0, y: 1.5 },
            &button_color,
            1.0
        );
        
        self.renderer.draw_quad(
            &Vector2 { x: -3.9, y: -2.25 }, 
            &Vector2 { x: 6.0, y: 1.5 },
            &Vector4 {
                x: 1.0,
                y: 1.0,
                z: 1.0,
                w: 1.0
            },
            2.0
        );

        self.renderer.end();
    }
}
