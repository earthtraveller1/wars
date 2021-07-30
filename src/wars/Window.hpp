#ifndef DCFA90B9_F708_49DA_AE1A_CF2950C12637
#define DCFA90B9_F708_49DA_AE1A_CF2950C12637

#include <GLFW/glfw3.h>
#include <string_view>

class Window {
private:
    GLFWwindow* window;
    unsigned int width;
    unsigned int height;
    
    // Create the window from a set of properties
    void create(bool fullscreen, std::string_view title);
public:
    // Make the input namespace a friend (it needs to access the private members)
    friend class Input;
    
    // Default Constructor
    Window();
    
    // Constructor
    Window(unsigned int width, unsigned int height, std::string_view title, bool fullscreen);
    
    // Constructor with automatic aspect ratio
    Window(double multiplier, std::string_view title, bool fullscreen);
    
    // Show the window
    void show();
    
    // Returns if the window is open or not
    bool isOpen();
    
    // Update the window
    void update();
    
    // Getter for the width
    unsigned int getWidth();
    
    // Getter for the height
    unsigned int getHeight();
    
    // Destroys the window
    ~Window();
};

#endif /* DCFA90B9_F708_49DA_AE1A_CF2950C12637 */
