#include <GLFW/glfw3.h>
#include "../Input.hpp"

#include "Button.hpp"

Button::Button(graphics::Mesh& mesh, const ClickBox& p_clickBox): Sprite(mesh), clickBox(p_clickBox) {
    
}

bool Button::isClicked() {
    // First, we have to convert GLFW's coordinates to our coordinates
    glm::vec2 mousePos = Input::getMousePos();
    int realMouseX = mousePos.x - 480;
    int realMouseY = 270 - mousePos.y;
    
    // Next, check for collision and mouse click. Just return it because the
    //  check itself is a boolean expression anyways.
    return 
    (
        (
            (realMouseX < clickBox.right && realMouseX > clickBox.left) &&
            (realMouseY < clickBox.top && realMouseY > clickBox.bottom)
        ) && Input::isMouseButtonDown(GLFW_MOUSE_BUTTON_LEFT)
    );
}

void Button::move(double x, double y) {
    Sprite::move(x, y);
    
    // Move the clickbox also
    clickBox.right  += x;
    clickBox.left   += x;
    clickBox.top    += y;
    clickBox.bottom += y;
    // I just added the formatting because I thought that it would look cooler.
}