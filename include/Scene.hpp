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
        
        static void setActiveScene(Scene& scene) { active = &scene; }
        
        static void updateActiveScene() { active->update(); }
        
        static void renderActiveScene() { active->render(); }
        
    private:
        // The active scene
        static Scene* active;
    };
}

#endif /* DD261990_8A77_4F57_97DD_946827F1FC8E */
