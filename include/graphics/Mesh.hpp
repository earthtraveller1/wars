#ifndef C0D911E7_8ADB_4629_80C3_A1DEEC083B8E
#define C0D911E7_8ADB_4629_80C3_A1DEEC083B8E

#include <graphics/Vertex.hpp>
#include <vector>

namespace graphics {
    // A Class that represents a Mesh. Really basic for now, since I don't have much special needs
    class Mesh {
    private:
        // Graphics Card object handles
        unsigned int vao;
        unsigned int vbo;
        unsigned int ebo;
        
        // The number of indices
        unsigned int numOfIndices;
        
        // Move ownership from another object
        void moveFrom(Mesh& src);
        
        // Destroy the Mesh
        void destroy();
        
    public:
        // Default Constructor
        Mesh();
        
        // Construct a Mesh from a vector of vertices and indices
        Mesh(std::vector<Vertex> vertices, std::vector<unsigned int> indices);
        
        // Copy constructor
        Mesh(Mesh& src);
        
        // Copy assignment operator
        Mesh& operator=(Mesh& rhs);
        
        // Move constructor
        Mesh(Mesh&& src);
        
        // Move assignment operator
        Mesh& operator=(Mesh&& rhs);
        
        // Render the Mesh
        void render();
        
        // Swap two sprites
        static void swap(Mesh& a, Mesh& b);
        
        // Destructor
        ~Mesh();
    };
}

#endif /* C0D911E7_8ADB_4629_80C3_A1DEEC083B8E */
