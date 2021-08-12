#ifndef A1363910_B5D1_4AAF_8CE0_4451C7FCD08F
#define A1363910_B5D1_4AAF_8CE0_4451C7FCD08F

#include "../Scene.hpp"
#include "../CollisionBox.hpp"

#include "../sprite-types/Player.hpp"
#include "../sprite-types/Zombie.hpp"

namespace graphics {
    class Sprite;
}

class CollisionBox;

class Scene1: public Scene {
public:
    Player player;
    
    Zombie zombie1;
    Zombie zombie2;
    Zombie zombie3;
    
    graphics::Sprite background;
    
public:
    // Default Constructor
    Scene1();
    
    virtual void render() override;
    
    virtual void update(double deltaTime) override;
};

#endif /* A1363910_B5D1_4AAF_8CE0_4451C7FCD08F */
