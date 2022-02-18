#include <scp/graphics/opengl.hpp>
#include <scp/graphics/API.hpp>
#include <scp/utils/file-utils.hpp>
#include <scp/Window.hpp>

#include "MenuScene.hpp"

namespace opengl = scp::graphics::opengl;
using scp::graphics::Sprite;
using scp::math::Vector2;
using scp::math::Vector4;
using scp::ui::Button;
using scp::graphics::Renderer2D;

const float playButtonWidth = 200.0f;
const float playButtonHeight = 100.0f;

MenuScene::MenuScene(Renderer2D& renderer): 
    m_renderer(renderer),
    m_playButtonHandler(200.0, 0.0, 0.0, 100.0)
{
    uint32_t windowWidth = scp::Window::getInstance().getWidth();
    uint32_t windowHeight = scp::Window::getInstance().getHeight();
    
    m_playButtonSprite.position = Vector2(windowWidth * (1.0f/6), windowHeight * (1.0f/3));
    m_playButtonSprite.scale = Vector2(playButtonWidth, playButtonHeight);
    m_playButtonSprite.baseColor = Vector4(1.0f, 0.0f, 0.0f, 1.0f);
    m_playButtonSprite.texture = 0;
    m_playButtonSprite.uv[0] = Vector2(playButtonWidth / 2048.0f, 0.0f);
    m_playButtonSprite.uv[1] = Vector2(playButtonWidth / 2048.0f, playButtonHeight / 2048.0f);
    m_playButtonSprite.uv[2] = Vector2(0.0f, playButtonHeight / 2048.0f);
    m_playButtonSprite.uv[3] = Vector2(0.0f, 0.0f);
    m_playButtonSprite.applyTransforms();
    
    m_playButtonHandler.move(windowWidth * (1.0f / 6.0f), windowHeight * (1.0f / 3.0f));
}

void MenuScene::onUpdate(double p_deltaTime)
{
    if (m_playButtonHandler.isHovering())
    {
        m_playButtonSprite.baseColor = Vector4(1.0f, 0.5f, 0.5f, 1.0f);
    }
    else 
    {
        m_playButtonSprite.baseColor = Vector4(1.0f, 0.0f, 0.0f, 1.0f);
    }
}

void MenuScene::render()
{
    m_renderer.begin();
    
    m_renderer.drawSprite(m_playButtonSprite);
    
    m_renderer.end();
}

MenuScene::~MenuScene()
{
    
}