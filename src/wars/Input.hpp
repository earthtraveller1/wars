#ifndef D7CDE22F_464B_42CB_A6A1_D57D4724A1EA
#define D7CDE22F_464B_42CB_A6A1_D57D4724A1EA

#include <glm/vec2.hpp>

class Window;

class Input {
public:
    // Is the specified key being pressed?
    static bool isKeyDown(int key);
    
    // Set the window to check for input from
    static void setWindow(Window& window);
    
    // Get the cursor x
    static int getMouseX();
    
    // Get the cursor y
    static int getMouseY();
    
    // Get the cursor position
    static glm::vec2 getMousePos();
    
    // check whether the mouse is clicked or not
    static bool isMouseButtonDown(int button);
    
    // Check whether the mouse is released or not
    static bool isMouseButtonReleased(int button);
};

#endif /* D7CDE22F_464B_42CB_A6A1_D57D4724A1EA */
