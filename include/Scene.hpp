#ifndef DD261990_8A77_4F57_97DD_946827F1FC8E
#define DD261990_8A77_4F57_97DD_946827F1FC8E

namespace wars
{
    // This is an abstract class that represents the basics of a scene, as well
    // as utility functions to handle the flow of scenes during the execution
    // of the game. It also acts as an abstraction layer that abstracts the
    // details of the Game class from the scenes.
    class Scene
    {
    public:
        Scene() {}
        
        virtual void update() = 0;
        
        virtual void render() = 0;
        
        virtual ~Scene() {}
        
        template<typename T>
        static void setActiveScene()
        {
            if (active != nullptr)
            {
                delete active;
                active = nullptr;
            }
            
            active = new T();
        }
        
        static void removeActiveScene();
        
        static void updateActiveScene() { active->update(); }
        
        static void renderActiveScene() { active->render(); }
        
    private:
        // The active scene
        static Scene* active;
    };
}

#endif /* DD261990_8A77_4F57_97DD_946827F1FC8E */
