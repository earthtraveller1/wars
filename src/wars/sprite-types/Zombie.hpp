#ifndef F7607218_8F2D_4F25_AF1D_CBC7C493EAFA
#define F7607218_8F2D_4F25_AF1D_CBC7C493EAFA

#include <graphics/Sprite.hpp>
#include "../CollisionBox.hpp"

class Zombie: public graphics::Sprite, public CollisionBox {
public:
    Zombie();
    
    virtual void move(double x, double y);
};

#endif /* F7607218_8F2D_4F25_AF1D_CBC7C493EAFA */
