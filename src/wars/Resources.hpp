#ifndef E7988B6C_E6C4_4EDD_9DAC_7C0AAB9EDC8A
#define E7988B6C_E6C4_4EDD_9DAC_7C0AAB9EDC8A

namespace graphics {
    class Mesh;
    class Material;
    class TextureAtlas;
    class Shader;
}

namespace Resources {
    namespace Meshes {
        extern graphics::Mesh* test;
        extern graphics::Mesh* player;
    }
    
    // Prepare the Meshes
    void prepareMeshes();
    
    namespace Shaders {
        extern graphics::Shader* defaultShader;
    }
    
    // Prepare the Shaders
    void prepareShaders();
    
    namespace TextureAtlases {
        extern graphics::TextureAtlas* test;
        extern graphics::TextureAtlas* atlas1;
    }
    
    // Prepare the Texture atlases
    void prepareTextureAtlases();
    
    namespace Materials {
        extern graphics::Material* test;
        extern graphics::Material* atlas1;
    }
    
    // Prepare the Materials
    void prepareMaterials();
}

#endif /* E7988B6C_E6C4_4EDD_9DAC_7C0AAB9EDC8A */
