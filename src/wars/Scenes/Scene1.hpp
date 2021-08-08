#ifndef A1363910_B5D1_4AAF_8CE0_4451C7FCD08F
#define A1363910_B5D1_4AAF_8CE0_4451C7FCD08F

#include "../Scene.hpp"

namespace graphics {
    class Sprite;
}

class Scene1: public Scene {
public:
    graphics::Sprite player;
    graphics::Sprite background;
    
public:
    // Default Constructor
    Scene1();
    
    virtual void render() override;
    
    virtual void update(double deltaTime) override;
};

#endif /* A1363910_B5D1_4AAF_8CE0_4451C7FCD08F */
