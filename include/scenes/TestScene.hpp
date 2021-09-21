#ifndef C32DE65B_193C_4675_A77E_2D558E3B681D
#define C32DE65B_193C_4675_A77E_2D558E3B681D

#include <Scene.hpp>

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
    };
}

#endif /* C32DE65B_193C_4675_A77E_2D558E3B681D */
