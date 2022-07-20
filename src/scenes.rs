use crate::core::Scene;

pub struct DummyScene {}

impl Scene for DummyScene {
    fn update(&mut self) {
        println!("bozo!");
    }
    
    fn render(&mut self) {
        println!("bogo");
    }
}