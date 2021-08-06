#ifndef B5AA26B1_009A_4288_B03C_2A1468B4E642
#define B5AA26B1_009A_4288_B03C_2A1468B4E642

class Window;

namespace wars {
    // The class that represents the entire application
    class Application {
    private:
        Window* window;
        
        // Prepare the window
        void initWindow();
        
        // Prepare the resources
        void initResources();
        
        // Prepare the scenes so that they can be rendered
        void initScenes();
        
        // Set the background color
        void initBackgroundColor();
    public:
        Application();
        
        void mainLoop();
        
        ~Application();
    };
}

#endif /* B5AA26B1_009A_4288_B03C_2A1468B4E642 */
