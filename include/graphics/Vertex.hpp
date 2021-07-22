#ifndef FF614E25_B729_47CE_BF77_CB83F03831E2
#define FF614E25_B729_47CE_BF77_CB83F03831E2

#include <glm/vec2.hpp>

namespace graphics {
    // A Struct which represents a single vertex. It does not only contain position, but also contain other information
    struct Vertex {
        glm::vec2 pos;
        glm::vec2 uv;
    };
}

#endif /* FF614E25_B729_47CE_BF77_CB83F03831E2 */
