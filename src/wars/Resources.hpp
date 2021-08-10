#ifndef E7988B6C_E6C4_4EDD_9DAC_7C0AAB9EDC8A
#define E7988B6C_E6C4_4EDD_9DAC_7C0AAB9EDC8A

namespace graphics {
    class Mesh;
    class TextureAtlas;
    class Shader;
}

namespace Resources {
    namespace Meshes {
        // Main screen stuff
        extern graphics::Mesh* scene0Background;
        extern graphics::Mesh* playButton;
        extern graphics::Mesh* otherButton;
        
        // Playing area
        extern graphics::Mesh* gameBackground;
        extern graphics::Mesh* player;
        extern graphics::Mesh* zombie;
    }
    
    // Prepare the Meshes
    void prepareMeshes();
    
    namespace Shaders {
        extern graphics::Shader* defaultShader;
    }
    
    // Prepare the Shaders
    void prepareShaders();
    
    namespace TextureAtlases {
        extern graphics::TextureAtlas* atlas0;
        extern graphics::TextureAtlas* atlas1;
    }
    
    // Prepare the Texture atlases
    void prepareTextureAtlases();
}

#endif /* E7988B6C_E6C4_4EDD_9DAC_7C0AAB9EDC8A */
