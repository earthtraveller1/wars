#ifndef DEF8B898_183A_498C_89FF_C2AD6C477FDF
#define DEF8B898_183A_498C_89FF_C2AD6C477FDF

#include <vector>

// This is a special type of singleton class that just manages shaders, destroys them when you don't need them anymore.

namespace graphics {
    class ShaderManager {
    private:
        // Vector of Shaders
        std::vector<unsigned int> shaders;
        
        // The latest index (incremented everytime you add a shader)
        unsigned int latestIndex = 0;
        
        // Made the constructors private so there can't be an instance
        ShaderManager();
        ShaderManager(ShaderManager& src);
        ShaderManager(ShaderManager&& src);
        
    public:
        // Returns the instance you need.
        static ShaderManager& getInstance();
        
        // Add a shader object to the vector and return the index
        unsigned int add(unsigned int shader);
        
        // Remove a shader object from the vector
        void remove(unsigned int index);
        
        // Destroys all the shaders that hasn't been destroyed.
        ~ShaderManager();
    };
}

#endif /* DEF8B898_183A_498C_89FF_C2AD6C477FDF */
