use std::{cell::RefCell, rc::Rc};

use crate::{
    graphics::Renderer2D,
    math::{Vector2, Vector4},
    ui::ButtonChecker,
    Scene, SceneManager, Window,
};
use rand::{distributions::Uniform, Rng};

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
    fn update(&mut self, _: f64) {
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
    button_handler: ButtonChecker,
    scene_manager: *mut SceneManager,
}

impl MenuScene {
    pub fn new(window: Rc<RefCell<Window>>, scene_manager: *mut SceneManager) -> MenuScene {
        let mut renderer = Renderer2D::new(
            3,
            "assets/shaders/2d_renderer_basic.vs",
            "assets/shaders/2d_renderer_basic.fs",
        );

        renderer.load_texture("assets/textures/backgrounds/main_menu_background.png", 0);
        renderer.load_texture("assets/textures/ui/play_button.png", 1);
        renderer.load_texture("assets/textures/ui/other_button.png", 2);

        return MenuScene {
            renderer: renderer,
            window,
            button_handler: ButtonChecker::new(),
            scene_manager,
        };
    }
}

impl Scene for MenuScene {
    fn update(&mut self, _: f64) {
        let (mouse_x, mouse_y) = self.window.borrow().get_mouse_position();
        self.button_handler.update_mouse_position(mouse_x, mouse_y);

        if self
            .window
            .borrow()
            .is_mouse_button_down(glfw::MouseButtonLeft)
        {
            if self
                .button_handler
                .is_button_hovered(80.0, 275.0, 200.0, 100.0)
            {
                unsafe {
                    (*(self.scene_manager))
                        .set_active(Box::new(GameScene::new(self.scene_manager, self.window.clone(), false)))
                };
            } else if self
                .button_handler
                .is_button_hovered(80.0, 400.0, 400.0, 100.0)
            {
                unsafe {
                    (*(self.scene_manager)).set_active(Box::new(HardModeMenuScene::new(
                        self.scene_manager,
                        self.window.clone(),
                    )))
                };
            }
        }
    }

    fn render(&mut self) {
        self.renderer.begin();

        self.renderer.draw_quad(
            &Vector2 { x: 0.0, y: 0.0 },
            &Vector2 {
                x: 1280.0,
                y: 720.0,
            },
            &Vector4 {
                x: 1.0,
                y: 1.0,
                z: 1.0,
                w: 1.0,
            },
            0.0,
        );

        let button_color = if self
            .button_handler
            .is_button_hovered(80.0, 275.0, 200.0, 100.0)
        {
            Vector4::from_scalar(0.7)
        } else {
            Vector4::from_scalar(1.0)
        };

        self.renderer.draw_quad(
            &Vector2 { x: 80.0, y: 275.0 },
            &Vector2 { x: 200.0, y: 100.0 },
            &button_color,
            1.0,
        );

        let button_color = if self
            .button_handler
            .is_button_hovered(80.0, 400.0, 400.0, 100.0)
        {
            Vector4::from_scalar(0.7)
        } else {
            Vector4::from_scalar(1.0)
        };

        self.renderer.draw_quad(
            &Vector2 { x: 80.0, y: 400.0 },
            &Vector2 { x: 400.0, y: 100.0 },
            &button_color,
            2.0,
        );

        self.renderer.end();
    }
}

struct Enemy {
    x_position: f32,
}

struct GameScene {
    renderer: Renderer2D,
    window: Rc<RefCell<Window>>,
    scene_manager: *mut SceneManager,

    player_texture: f32,
    player_position: f32,

    enemy_texture: f32,
    enemies: Vec<Enemy>,

    is_hard_mode: bool,
}

impl GameScene {
    fn new(scene_manager: *mut SceneManager, window: Rc<RefCell<Window>>, is_hard_mode: bool) -> GameScene {
        let mut renderer = Renderer2D::new(
            5,
            "assets/shaders/2d_renderer_basic.vs",
            "assets/shaders/2d_renderer_basic.fs",
        );

        renderer.load_texture("assets/textures/backgrounds/game_background.png", 0);
        renderer.load_texture("assets/textures/props/can_pooper.png", 1);
        renderer.load_texture("assets/textures/props/rai_rai_raku_raku.png", 2);

        let mut random_generator = rand::thread_rng();
        let distribution: Uniform<i32> = Uniform::from(1..3);
        let player_texture = random_generator.sample(distribution);

        println!("{}", player_texture);

        let (player_texture, enemy_texture) = if player_texture == 1 {
            (1.0, 2.0)
        } else {
            (2.0, 1.0)
        };

        GameScene {
            renderer,
            player_texture,
            enemy_texture,
            enemies: vec![
                Enemy { x_position: 1000.0 },
                Enemy { x_position: 800.0 },
                Enemy { x_position: 600.0 },
            ],
            window,
            player_position: 200.0,
            is_hard_mode,
            scene_manager
        }
    }
}

impl Scene for GameScene {
    fn update(&mut self, delta_time: f64) {
        const PLAYER_SPEED: f32 = 200.0;

        if self.window.borrow().is_key_down(glfw::Key::Left) {
            self.player_position -= PLAYER_SPEED * (delta_time as f32);
        }
        if self.window.borrow().is_key_down(glfw::Key::Right) {
            self.player_position += PLAYER_SPEED * (delta_time as f32);
        }

        if self.is_hard_mode {
            self.enemies.iter_mut().for_each(|enemy| {
                enemy.x_position -= (50.0f64 * delta_time) as f32;
            });
            
            if (self.enemies[2].x_position - self.player_position).abs() < 150.0 {
                unsafe { (*(self.scene_manager)).set_active(Box::new(MenuScene::new(self.window.clone(), self.scene_manager))) };
            }
        }
    }

    fn render(&mut self) {
        self.renderer.begin();

        self.renderer.draw_quad(
            &Vector2 { x: 0.0, y: 0.0 },
            &Vector2 {
                x: 1280.0,
                y: 720.0,
            },
            &Vector4 {
                x: 1.0,
                y: 1.0,
                z: 1.0,
                w: 1.0,
            },
            0.0,
        );

        self.renderer.draw_quad(
            &Vector2 {
                x: self.player_position,
                y: 370.0,
            },
            &Vector2 { x: 150.0, y: 150.0 },
            &Vector4 {
                x: 1.0,
                y: 1.0,
                z: 1.0,
                w: 1.0,
            },
            self.player_texture,
        );

        self.enemies.iter().for_each(|enemy| {
            self.renderer.draw_quad(
                &Vector2 {
                    x: enemy.x_position,
                    y: 370.0,
                },
                &Vector2 { x: 150.0, y: 150.0 },
                &Vector4 {
                    x: 1.0,
                    y: 1.0,
                    z: 1.0,
                    w: 1.0,
                },
                self.enemy_texture,
            );
        });

        self.renderer.end();
    }
}

struct HardModeMenuScene {
    renderer: Renderer2D,
    scene_manager: *mut SceneManager,
    window: Rc<RefCell<Window>>,
    button_handler: ButtonChecker,
}

impl HardModeMenuScene {
    fn new(scene_manager: *mut SceneManager, window: Rc<RefCell<Window>>) -> HardModeMenuScene {
        let mut renderer = Renderer2D::new(
            3,
            "assets/shaders/2d_renderer_basic.vs",
            "assets/shaders/2d_renderer_basic.fs",
        );

        renderer.load_texture(
            "assets/textures/backgrounds/hard_mode_menu_background.png",
            0,
        );
        renderer.load_texture("assets/textures/ui/yes_button.png", 1);
        renderer.load_texture("assets/textures/ui/no_button.png", 2);

        let button_handler = ButtonChecker::new();

        return HardModeMenuScene {
            renderer,
            scene_manager,
            window,
            button_handler,
        };
    }
}

impl Scene for HardModeMenuScene {
    fn update(&mut self, _delta_time: f64) {
        let (mouse_x, mouse_y) = self.window.borrow().get_mouse_position();
        self.button_handler.update_mouse_position(mouse_x, mouse_y);

        if self
            .window
            .borrow()
            .is_mouse_button_down(glfw::MouseButtonLeft)
        {
            if self
                .button_handler
                .is_button_hovered((1280.0 - 200.0) / 2.0, 330.0, 200.0, 100.0)
            {
                unsafe {
                    (*(self.scene_manager))
                        .set_active(Box::new(GameScene::new(self.scene_manager, self.window.clone(), true)))
                };
            } else if self.button_handler.is_button_hovered(
                (1280.0 - 200.0) / 2.0,
                450.0,
                200.0,
                100.0,
            ) {
                unsafe {
                    (*(self.scene_manager)).set_active(Box::new(MenuScene::new(
                        self.window.clone(),
                        self.scene_manager,
                    )))
                };
            }
        }
    }

    fn render(&mut self) {
        self.renderer.begin();

        self.renderer.draw_quad(
            &Vector2 { x: 0.0, y: 0.0 },
            &Vector2 {
                x: 1280.0,
                y: 720.0,
            },
            &Vector4 {
                x: 1.0,
                y: 1.0,
                z: 1.0,
                w: 1.0,
            },
            0.0,
        );

        self.renderer.draw_quad(
            &Vector2 {
                x: (1280.0 - 200.0) / 2.0,
                y: 330.0,
            },
            &Vector2 { x: 200.0, y: 100.0 },
            &(if self
                .button_handler
                .is_button_hovered((1280.0 - 200.0) / 2.0, 330.0, 200.0, 100.0)
            {
                Vector4 {
                    x: 0.7,
                    y: 0.7,
                    z: 0.7,
                    w: 0.7,
                }
            } else {
                Vector4 {
                    x: 1.0,
                    y: 1.0,
                    z: 1.0,
                    w: 1.0,
                }
            }),
            1.0,
        );

        self.renderer.draw_quad(
            &Vector2 {
                x: (1280.0 - 200.0) / 2.0,
                y: 450.0,
            },
            &Vector2 { x: 200.0, y: 100.0 },
            &(if self
                .button_handler
                .is_button_hovered((1280.0 - 200.0) / 2.0, 450.0, 200.0, 100.0)
            {
                Vector4 {
                    x: 0.7,
                    y: 0.7,
                    z: 0.7,
                    w: 0.7,
                }
            } else {
                Vector4 {
                    x: 1.0,
                    y: 1.0,
                    z: 1.0,
                    w: 1.0,
                }
            }),
            2.0,
        );

        self.renderer.end();
    }
}
