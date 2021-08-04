#ifndef EBDCA3D9_0B00_42FB_86A8_97C1AA0D640E
#define EBDCA3D9_0B00_42FB_86A8_97C1AA0D640E

#include <graphics/Sprite.hpp>

struct ClickBox {
    int right;
    int left;
    int top;
    int bottom;
};

class Button: public graphics::Sprite {
private:
    // The Click box for clicking
    ClickBox clickBox;
    
public:
    // Construct from Mesh and a click box object
    Button(graphics::Mesh& mesh, const ClickBox& clickBox = { 100, -100, 100, -100 });
    
    // Is the button being clicked?
    bool isClicked();
    
    // Move the button around
    virtual void move(float x, float y) override;
};

#endif /* EBDCA3D9_0B00_42FB_86A8_97C1AA0D640E */
