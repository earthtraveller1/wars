#ifndef CB07792D_8AAF_4B66_B9AB_739DDBFFDEA7
#define CB07792D_8AAF_4B66_B9AB_739DDBFFDEA7

namespace graphics {
    class Sprite;
}

class CollisionBox;

class Bullet: public graphics::Sprite, public CollisionBox {
public:
    Bullet();
    
    virtual void move(double x, double y);
}

#endif /* CB07792D_8AAF_4B66_B9AB_739DDBFFDEA7 */
