#include <scenes/TestScene.hpp>

using wars::scenes::TestScene;

using wars::graphics::Shaders;
using wars::graphics::Sprite;

TestScene::TestScene(): 
    m_shaders(Shaders::getInstance()),
    m_hello({
        { {  0.5,  0.5 }, { 0.0, 0.0 } },
        { {  0.5, -0.5 }, { 0.0, 0.0 } },
        { { -0.5, -0.5 }, { 0.0, 0.0 } },
        { { -0.5,  0.5 }, { 0.0, 0.0 } }
    }, {
        0, 1, 2,
        0, 3, 2
    })
{
    
}





void TestScene::update()
{
    
}




void TestScene::render()
{
    m_shaders.useSolidColor();
    m_shaders.getSolidColorShader().setUniform("baseColor", 1.0, 1.0, 1.0, 1.0);
}




TestScene::~TestScene()
{
    
}