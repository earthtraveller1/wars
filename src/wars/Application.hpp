#ifndef B5AA26B1_009A_4288_B03C_2A1468B4E642
#define B5AA26B1_009A_4288_B03C_2A1468B4E642

class Window;

namespace wars {
    // The class that represents the entire application
    class Application {
    private:
        Window* window;
    public:
        Application();
        
        void mainLoop();
        
        ~Application();
    };
}

#endif /* B5AA26B1_009A_4288_B03C_2A1468B4E642 */
