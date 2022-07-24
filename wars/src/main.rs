use wars::Game;

fn main() {
    let mut game = Game::new();
    game.init();

    while game.is_running() {
        game.update();
    }
}
