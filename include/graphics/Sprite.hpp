#ifndef DCF0C048_29F6_4EC8_8D7E_34707C8BC96E
#define DCF0C048_29F6_4EC8_8D7E_34707C8BC96E

#include <glm/mat4x4.hpp>

namespace graphics {
    class Mesh;
    
    class Shader;
    
    // A Class to represent a sprite. Basic for now, add more features later on.
    class Sprite {
    private:
        // The Mesh of the sprite (typically a rectangle)
        Mesh& mesh;
        
        // The model matrix
        glm::mat4 modelMatrix;
        
    public:
        // Constructor
        Sprite(Mesh& mesh);
        
        // Draw the sprite
        void draw(Shader& shader);
        
        // Move the sprite
        void move(float x, float y);
        
        // Turn the sprite
        void turn(float degrees);
    };
}

#endif /* DCF0C048_29F6_4EC8_8D7E_34707C8BC96E */
