#ifndef A7CC729D_FF40_4283_AC11_9FC988D192E9
#define A7CC729D_FF40_4283_AC11_9FC988D192E9

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
        
    private:
        // Default constructor
        Shader() = default;
        
        // Constructor from a path to the file containing the shader
        Shader(std::string_view path);
        
        // The handle to the actual shader program
        unsigned int m_shader;
    };
}

#endif /* A7CC729D_FF40_4283_AC11_9FC988D192E9 */
