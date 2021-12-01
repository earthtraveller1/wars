#ifndef A7CC729D_FF40_4283_AC11_9FC988D192E9
#define A7CC729D_FF40_4283_AC11_9FC988D192E9

#include <pch.hpp>

namespace wars::graphics
{
    // A class built to handle a OpenGL shader. It is very basic for now. I 
    // didn't implement any RAII functions since there will only be two of them
    // during the entire execution state of the program.
    class Shader
    {
    public:
        // The class containing the shader instances needs to be friends since 
        // the constructors will be private
        friend class Shaders;
        
        // Set a uniform that's an integer
        void setUniform(std::string_view name, int32_t value) { glUniform1i(glGetUniformLocation(m_shader, name.data()), value); }
        
        // Set a uniform that's a matrix
        template<typename T>
        void setUniform(std::string_view name, math::Matrix4<T> value) { glUniformMatrix4fv(glGetUniformLocation(m_shader, name.data()), 1, GL_FALSE, value.data()); }
        
        // Set a uniform that's a 4 valued vector
        void setUniform(std::string_view name, float x, float y, float z, float w) { glUniform4f(glGetUniformLocation(m_shader, name.data()), x, y, z, w); }
        
    private:
        // Default constructor
        Shader() = default;
        
        // Constructor from a string containing the source of the shader
        Shader(std::string_view source);
        
        // The handle to the actual shader program
        unsigned int m_shader;
    };
}

#endif /* A7CC729D_FF40_4283_AC11_9FC988D192E9 */
