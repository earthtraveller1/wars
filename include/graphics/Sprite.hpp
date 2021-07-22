#ifndef C0D911E7_8ADB_4629_80C3_A1DEEC083B8E
#define C0D911E7_8ADB_4629_80C3_A1DEEC083B8E

#include <graphics/Vertex.hpp>
#include <vector>
#include <graphics/Material.hpp>

namespace graphics {
    // A Class that represents a sprite. Really basic for now, since I don't have much special needs
    class Sprite {
    private:
        // Graphics Card object handles
        unsigned int vao;
        unsigned int vbo;
        unsigned int ebo;
        
        // Material
        Material material;
        
        // Move ownership from another object
        void moveFrom(Sprite& src);
        
        // Destroy the sprite
        void destroy();
        
    public:
        // Default Constructor
        Sprite();
        
        // Construct a Object from a vector of vertices
        Sprite(std::vector<Vertex> vertices);
        
        // Construct a Sprite from a vector of vertices and indices
        Sprite(std::vector<Vertex> vertices, std::vector<unsigned int> indices);
        
        // Copy constructor
        Sprite(Sprite& src);
        
        // Copy assignment operator
        Sprite& operator=(Sprite& rhs);
        
        // Move constructor
        Sprite(Sprite&& src);
        
        // Move assignment operator
        Sprite& operator=(Sprite&& rhs);
        
        // Render the sprite
        void render();
        
        // Swap two sprites
        static void swap(Sprite& a, Sprite& b);
        
        // Destructor
        ~Sprite();
    };
}

#endif /* C0D911E7_8ADB_4629_80C3_A1DEEC083B8E */
