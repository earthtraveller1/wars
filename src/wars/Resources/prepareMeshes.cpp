#include <graphics/Mesh.hpp>

#include "../Resources.hpp"

using namespace Resources::Meshes;
using graphics::Mesh;

Mesh* Resources::Meshes::scene0Background = nullptr;
Mesh* Resources::Meshes::playButton = nullptr;
Mesh* Resources::Meshes::otherButton = nullptr;

Mesh* Resources::Meshes::player = nullptr;

void Resources::prepareMeshes() {
    scene0Background = new Mesh(
        {
            {
                { 480.0f, 270.0f },
                { 0.960f, 0.0f }
            },
            {
                { 480.0f, -270.0f },
                { 0.960f, 0.540f }
            },
            {
                { -480.0f, -270.0f },
                { 0.0f, 0.540f }
            },
            {
                { -480.0f, 270.0f },
                { 0.0f, 0.0f }
            }
        },
        {
            0, 1, 2, 0, 3, 2
        }
    );
    
    
    
    otherButton = new Mesh(
        {
            {
                { 102.5f, 37.5f },
                { 0.205f, 0.538f },
            },
            {
                { 102.5f, -37.5f },
                { 0.205f, 0.613f },
            },
            {
                { -102.5f, -37.5f },
                { 0.0f, 0.613f },
            },
            {
                { -102.5f, 37.5f },
                { 0.0f, 0.538f },
            }
        },
        {
            0, 1, 2, 0, 3, 2
        }
    );
    
    
    
    playButton = new Mesh(
        {
            {
                { 78.0f, 37.5f },
                { 0.362f, 0.538f },
            },
            {
                { 78.0f, -37.5f },
                { 0.362f, 0.613f },
            },
            {
                { -78.0f, -37.5f },
                { 0.206f, 0.613f },
            },
            {
                { -78.0f, 37.5f },
                { 0.206f, 0.538f },
            }
        },
        {
            0, 1, 2, 0, 3, 2
        }
    );
    
    
    
    player = new Mesh(
        {
            {
                { 58.0, 65.5 },
                { 0.116, 0.0 }
            },
            {
                { 58.0, -65.5 },
                { 0.116, 0.131 }
            },
            {
                { -58.0, -65.5 },
                { 0.0, 0.131 }
            },
            {
                { -58.0, 65.5 },
                { 0.0, 0.0 }
            }
        },
        {
            0, 1, 2, 0, 3, 2
        }
    );
}