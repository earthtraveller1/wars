#include <graphics/Sprite.hpp>
#include "../CollisionBox.hpp"
#include "../Resources.hpp"

#include "Bullet.hpp"

Bullet::Bullet(): Sprite(*Resources::Meshes::bullet), CollisionBox(10.0, -10.0, 3.0, -3.0) {
    
}

void Bullet::move(double x, double y) {
    Sprite::move(x, y);
    if (dir == graphics::Direction::LEFT) {
        CollisionBox::move(-x, y);
    } else {
        CollisionBox::move(x, y);
    }
}