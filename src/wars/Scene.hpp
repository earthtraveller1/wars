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
    std::vector<graphics::Sprite> sprites;
    
    // The scene that is currently active
    static Scene* active;
public:
    // Default Constructor, initializes an empty vector
    Scene() = default;
    
    // Construct from a vector of sprites
    Scene(std::vector<graphics::Sprite>& sprites);
    Scene(std::vector<graphics::Sprite>&& sprites);
    
    // Render the scene
    void render();
    
    // Set the active scene
    static void setActive(Scene& newActive);
    
    // Render the active scene
    static void renderActive();
};

#endif /* AE31E619_96C8_4000_8724_D323B6A6BDB4 */
