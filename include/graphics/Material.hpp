#ifndef A2307F2D_7981_4658_A5F3_C2244BB71B37
#define A2307F2D_7981_4658_A5F3_C2244BB71B37

#include <graphics/Shader.hpp>

namespace graphics {
    // A Class that represents a specific material
    class Material {
    private:
        // The shader
        Shader shader;
        
    public:
        // Default Constructor
        Material();
        
        // Constructor specifying shader
        Material(Shader shader);
        
        // Use the material
        void use();
        
        // Set a uniform
        template<typename T>
        void setUniform(std::string_view name, T value) {
            shader.setUniform(name, value);
        }
    };
}

#endif /* A2307F2D_7981_4658_A5F3_C2244BB71B37 */
