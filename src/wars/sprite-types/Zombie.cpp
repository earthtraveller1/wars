#include "../Resources.hpp"

#include "Zombie.hpp"

Zombie::Zombie(): Sprite(*Resources::Meshes::zombie), CollisionBox(36.0, -36.0, 65.5, -65.5) {
    
}

void Zombie::move(double x, double y) {
    Sprite::move(x, y);
    if (dir == graphics::Direction::LEFT) {
        CollisionBox::move(-x, y);
    } else {
        CollisionBox::move(x, y);
    }
}