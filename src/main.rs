use wars::Game;

fn main() {
    let mut game = Game::new();
    
    while game.is_running() {
        game.update()
    }
}
