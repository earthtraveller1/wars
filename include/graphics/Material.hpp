#ifndef A2307F2D_7981_4658_A5F3_C2244BB71B37
#define A2307F2D_7981_4658_A5F3_C2244BB71B37

#include <graphics/Shader.hpp>
#include <graphics/TextureAtlas.hpp>

namespace graphics {
    // A Class that represents a specific material
    class Material {
    private:
        // The shader
        Shader& shader;
        
        // The target texture atlas
        TextureAtlas& textureAtlas;
        
    public:
        // Constructor specifying shader
        Material(Shader& shader, TextureAtlas& textureAtlas);
        
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
