#ifndef C32DE65B_193C_4675_A77E_2D558E3B681D
#define C32DE65B_193C_4675_A77E_2D558E3B681D

#include <Scene.hpp>

#include <graphics/Shaders.hpp>
#include <graphics/Sprite.hpp>

namespace wars::scenes
{
    // A Scene that was created merely for testing purposes. It will be removed
    // once I am done testing the engine (though it's source files will stay in
    // the repository).
    class TestScene: public Scene
    {
    public:
        TestScene();
        
        virtual void update() override;
        
        virtual void render() override;
        
        virtual ~TestScene();
    private:
        graphics::Shaders& m_shaders;
        graphics::Sprite m_hello;
    };
}

#endif /* C32DE65B_193C_4675_A77E_2D558E3B681D */
