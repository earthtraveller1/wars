#ifndef AE31E619_96C8_4000_8724_D323B6A6BDB4
#define AE31E619_96C8_4000_8724_D323B6A6BDB4

namespace std {
    template<typename T, typename alloc>
    class vector;
}

namespace graphics {
    class Sprite;
}

class Scene {
private:
    // The scene that is currently active
    static Scene* active;
public:
    // Default Constructor
    Scene();
    
    // Render the scene
    virtual void render() = 0;
    
    // Update the scene
    virtual void update() = 0;
    
    // Set the active scene
    static void setActive(Scene* newActive);
    
    // Render the active scene
    static void renderActive();
    
    // Update the active scene
    static void updateActive();
};

#endif /* AE31E619_96C8_4000_8724_D323B6A6BDB4 */
