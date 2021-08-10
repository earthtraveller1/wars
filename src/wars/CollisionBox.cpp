#include "CollisionBox.hpp"

bool CollisionBox::collided(const CollisionBox& target) {
    return (
        ((top < target.top && top > target.bottom) || (bottom > target.bottom && bottom < target.top)) && 
        ((right < target.right && right > target.left) || (left < target.left && left > target.right))
    );
}