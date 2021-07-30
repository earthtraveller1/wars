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
        graphics::Mesh* test;
    }
    
    // Prepare the Meshes
    void prepareMeshes();
    
    namespace Shaders {
        graphics::Shader* defaultShader;
    }
    
    // Prepare the Shaders
    void prepareShaders();
    
    namespace TextureAtlases {
        graphics::TextureAtlas* test;
    }
    
    // Prepare the Texture atlases
    void prepareTextureAtlases();
    
    namespace Materials {
        graphics::Material* test;
    }
    
    // Prepare the Materials
    void prepareMaterials();
}

#endif /* E7988B6C_E6C4_4EDD_9DAC_7C0AAB9EDC8A */
