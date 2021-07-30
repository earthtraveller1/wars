#ifndef DCF0C048_29F6_4EC8_8D7E_34707C8BC96E
#define DCF0C048_29F6_4EC8_8D7E_34707C8BC96E

#include <glm/mat4x4.hpp>

namespace graphics {
    class Mesh;
    
    class Material;
    
    // A Class to represent a sprite. Basic for now, add more features later on.
    class Sprite {
    private:
        // The Mesh of the sprite (typically a rectangle)
        Mesh& mesh;
        
        // The Material of the sprite
        Material& material;
        
        // The model matrix
        glm::mat4 modelMatrix;
        
    public:
        // Constructor
        Sprite(Mesh& mesh, Material& material);
        
        // Draw the sprite
        void draw();
        
        // Move the sprite
        void move(int x, int y);
        
        // Turn the sprite
        void turn(float degrees);
    };
}

#endif /* DCF0C048_29F6_4EC8_8D7E_34707C8BC96E */