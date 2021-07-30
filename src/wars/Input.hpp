#ifndef D7CDE22F_464B_42CB_A6A1_D57D4724A1EA
#define D7CDE22F_464B_42CB_A6A1_D57D4724A1EA

class Window;

class Input {
public:
    // Is the specified key being pressed?
    static bool isKeyDown(int key);
    
    // Set the window to check for input from
    static void setWindow(Window& window);
};

#endif /* D7CDE22F_464B_42CB_A6A1_D57D4724A1EA */
