#ifndef B84FAA61_C9C7_4546_901C_4F06F96A2EFA
#define B84FAA61_C9C7_4546_901C_4F06F96A2EFA

#include <scp/Scene.hpp>

#include <scp/graphics/Renderer2D.hpp>
#include <scp/graphics/Sprite.hpp>

#include <scp/ui/Button.hpp>

class MenuScene: public scp::Scene
{
public:
    MenuScene(scp::graphics::Renderer2D& renderer);
    
    void onUpdate(double deltaTime) override;
    
    void render() override;
    
    ~MenuScene() override;
private:
    // The renderer
    scp::graphics::Renderer2D& m_renderer;
    
    // The play button
    scp::graphics::Sprite m_playButtonSprite;
    scp::ui::Button m_playButtonHandler;
};

#endif /* B84FAA61_C9C7_4546_901C_4F06F96A2EFA */
