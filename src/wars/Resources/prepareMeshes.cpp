#include <graphics/Mesh.hpp>

#include "../Resources.hpp"

using namespace Resources::Meshes;
using graphics::Mesh;

Mesh* Resources::Meshes::player = nullptr;

void Resources::prepareMeshes() {
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