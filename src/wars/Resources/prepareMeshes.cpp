#include <graphics/Mesh.hpp>

#include "../Resources.hpp"

using namespace Resources::Meshes;
using graphics::Mesh;

Mesh* Resources::Meshes::test = nullptr;

void Resources::prepareMeshes() {
    test = new Mesh(
        {
            {
                { 100.0, 100.0 },
                { 1.0, 1.0 }
            },
            {
                { 100.0, -100.0 },
                { 1.0, 0.0 }
            },
            {
                { -100.0, -100.0 },
                { 0.0, 0.0 }
            },
            {
                { -100.0, 100.0 },
                { 0.0, 1.0 }
            }
        },
        {
            0, 1, 2, 0, 3, 2
        }
    );
}