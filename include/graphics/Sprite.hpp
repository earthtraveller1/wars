#ifndef D1B01983_88B3_4F44_851C_894D2F00BFF7
#define D1B01983_88B3_4F44_851C_894D2F00BFF7

#include <graphics/Vertex.hpp>
#include <pch.hpp>

namespace wars::graphics
{
    // A enumeration that represents which direction a sprite is facing.
    enum class SpriteDirection
    {
        LEFT,
        RIGHT
    };
    
    
    
    
    // A class to represent a Sprite, which is a two dimensional object that
    // can be rendered on to the screen with OpenGL.
    class Sprite
    {
    public:
        // Default constructor
        Sprite() = default;
        
        // Create a sprite from a list of vertices and indices
        Sprite(std::vector<Vertex> vertices, std::vector<uint8_t> indices);
        
        // Create a Sprite from another sprite
        Sprite(Sprite& src);
        
        // Create a Sprite from another sprite that's also a lvalue
        Sprite(Sprite&& src);
        
        // Copy assignment operator
        Sprite& operator=(Sprite& src);
        
        // Move assignment operator
        Sprite& operator=(Sprite&& src);
        
        // Render the sprite
        void render();
        
        // Move the sprite
        void move(double x, double y);
        void move(math::Vector2<double> t);
        
        // Rotate the sprite
        void turn(double degrees);
        
        // Set the direction of the sprite
        void setDir(SpriteDirection newDir);
        
        // Destroys the sprite
        ~Sprite();
        
    private:
        // The direction of the sprite
        SpriteDirection m_direction;
        
        // OpenGL objects
        unsigned int m_vao;
        unsigned int m_vbo;
        unsigned int m_ebo;
        
        // Model matrix
        math::Matrix4<double> m_model;
    };
}

#endif /* D1B01983_88B3_4F44_851C_894D2F00BFF7 */
