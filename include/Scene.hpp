#ifndef DD261990_8A77_4F57_97DD_946827F1FC8E
#define DD261990_8A77_4F57_97DD_946827F1FC8E

namespace wars
{
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
