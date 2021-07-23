#ifndef D41FEB62_166D_44F6_AF61_33D30907876C
#define D41FEB62_166D_44F6_AF61_33D30907876C

#include <string_view>

namespace graphics {
    // A Class which represents a texture. Very basic for now, with basic raii
    class TextureAtlas {
    private:
        // The handle to the real texture object
        int texture;
        
        // The index of the texture atlas
        unsigned int index;
        
    public:
        // Default Constructor
        TextureAtlas();
        
        // Constructor from a file path
        TextureAtlas(std::string_view imagePath);
        
        // Bind the texture atlas
        void bind();
        
        // Unbind any texture atlases that are currently bound
        static void unbind();
        
        // Destroy the texture atlas
        void destroy();
    };
}

#endif /* D41FEB62_166D_44F6_AF61_33D30907876C */
