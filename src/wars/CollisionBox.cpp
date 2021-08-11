#include "CollisionBox.hpp"

CollisionBox::CollisionBox(double p_right, double p_left, double p_top, double p_bottom):
right(p_right), left(p_left), top(p_top), bottom(p_bottom) {
    
}

bool CollisionBox::collided(const CollisionBox& target) const {
    return 
    (left <= target.right && left >= target.left) || (right >= target.left && right <= target.right) &&
    (bottom <= target.top && bottom >= target.bottom) || (top >= target.bottom && top <= target.top);
}

void CollisionBox::move(double x, double y) {
    right += x;
    left += x;
    
    top += y;
    bottom += y;
}