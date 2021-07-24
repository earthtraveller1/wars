#ifndef D0C2FD95_F1CF_46DB_ACFB_EC73D871C43A
#define D0C2FD95_F1CF_46DB_ACFB_EC73D871C43A

#include <string_view>
#include <glm/mat4x4.hpp>

// The shader class, which represents a OpenGL Shader.

namespace graphics {
    class Shader {
    private:
        // The handle to the shader program
        unsigned int program;
        
        // Destroys the shader
        void destroy();
        
        // Move from another shader
        void moveFrom(Shader& src);
        
    public:
        // The default constructor
        Shader();
        
        // Constructs a Shader object from a shader source
        Shader(std::string_view path);
        
        // Constructs a Shader object from a vertex source and a fragment source
        Shader(std::string_view vertexPath, std::string_view fragmentPath, std::string_view name);
        
        // Copy constructor and assignment operator
        Shader(Shader& src);
        Shader& operator=(Shader& rhs);
        
        // Move constructor and assignment operator
        Shader(Shader&& src);
        Shader& operator=(Shader&& rhs);
        
        // Use the program
        void use();
        
        // Utility functions for setting uniforms
        void setUniform(std::string_view name, int value);
        void setUniform(std::string_view name, glm::mat4 value);
        
        // Destroy the object
        ~Shader();
    };
}

#endif /* D0C2FD95_F1CF_46DB_ACFB_EC73D871C43A */
