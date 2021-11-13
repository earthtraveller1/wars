#ifndef CD5F4E5A_5D5B_4119_B19F_82EDCC942E51
#define CD5F4E5A_5D5B_4119_B19F_82EDCC942E51

#include <glad/glad.h>
#include <GameOptions.hpp>
#include <graphics/Shader.hpp>

namespace wars::graphics
{
    class Shader;
    
    // A singleton class that acts as a container for the two Shader objects 
    // that are going to be used in this program.
    class Shaders
    {
    public:
        // Obtain an instance of this class
        static Shaders& getInstance();
        
        // Get the solid color shader's handle
        unsigned int getSolidColorHandle() { return m_solidColor.m_shader; }
        
        // Get the textured shader's handle
        unsigned int getTexturedHandle() { return m_textured.m_shader; }
        
        // Get a reference to the actual solid color shader's object
        Shader& getSolidColorShader() { return m_solidColor; }
        
        // Get a reference to the actual textured shader's object
        Shader& getTexturedShader() { return m_textured; }
        
        // Use the solid color shader
        void useSolidColor() { glUseProgram(m_solidColor.m_shader); }
        
        // Use the textured shader
        void useTextured() { glUseProgram(m_solidColor.m_shader); }
    private:
        // Default Constructor
        Shaders():
        m_solidColor(loadAsString(GameOptions::assetLocation + "shaders/solid_color.glsl")),
        m_textured(loadAsString(GameOptions::assetLocation + "shaders/textured.glsl"))
        {}
        
        // The solid color shader
        Shader m_solidColor;
        
        // The textured shader
        Shader m_textured;
        
        // Utility function to load shaders from the filesystem
        std::string loadAsString(std::string_view path);
    };
}

#endif /* CD5F4E5A_5D5B_4119_B19F_82EDCC942E51 */
