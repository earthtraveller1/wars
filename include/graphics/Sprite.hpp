#ifndef DCF0C048_29F6_4EC8_8D7E_34707C8BC96E
#define DCF0C048_29F6_4EC8_8D7E_34707C8BC96E

#include <glm/mat4x4.hpp>

namespace graphics {
    class Mesh;
    
    class Shader;
    
    enum class Direction {
        LEFT, RIGHT
    };
    
    // A Class to represent a sprite. Basic for now, add more features later on.
    class Sprite {
    private:
        // The Mesh of the sprite (typically a rectangle)
        Mesh& mesh;
        
        // The model matrix
        glm::mat4 modelMatrix;
        
        // The direction that the sprite is facing
        Direction dir;
        
    public:
        // Constructor
        Sprite(Mesh& mesh);
        
        // Draw the sprite
        void draw(Shader& shader);
        
        // Move the sprite
        virtual void move(float x, float y);
        
        // Turn the sprite
        virtual void turn(float degrees);
        
        // Set the direction that the sprite is facing
        virtual void setDirection(Direction dir);
    };
}

#endif /* DCF0C048_29F6_4EC8_8D7E_34707C8BC96E */
