#ifndef D41FEB62_166D_44F6_AF61_33D30907876C
#define D41FEB62_166D_44F6_AF61_33D30907876C

#include <string_view>

namespace graphics {
    // A Class which represents a texture. Very basic for now, with basic raii
    class Texture {
    private:
        // The handle to the real texture object
        int texture;
        
    public:
        // Default Constructor
        Texture();
        
        // Constructor from a file path
        Texture(std::string_view imagePath);
        
        // Bind the texture
        void bind();
        
        // Unbind any texture that are currently bound
        static void unbind();
        
        // Destroy the texture
        void destroy();
    };
}

#endif /* D41FEB62_166D_44F6_AF61_33D30907876C */
