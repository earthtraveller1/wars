#include <glad/glad.h>
#include <graphics/gldb.hpp>

#include <graphics/basic-utils.hpp>

void bgu::clear() {
    glCall(glClear, GL_COLOR_BUFFER_BIT);
}