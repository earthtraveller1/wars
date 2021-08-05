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