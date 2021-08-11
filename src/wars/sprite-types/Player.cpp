#include "../Resources.hpp"

#include "Player.hpp"

Player::Player(): Sprite(*Resources::Meshes::player), CollisionBox(91.5, -91.5, 64.0, -64.0) {
    
}

void Player::move(double x, double y) {
    Sprite::move(x, y);
    CollisionBox::move(x, y);
}