//@ vertex
#version 330 core

layout (location = 0) in vec2 aPos;
layout (location = 1) in vec2 aUV;

uniform mat4 model;
uniform mat4 projection;

out vec2 uv;

void main() {
    gl_Position = projection * model * vec4(aPos.x, aPos.y, 0.0, 1.0);
    uv = aUV;
}

//@ fragment
#version 330 core

out vec4 colour;

in vec2 uv;

uniform sampler2D myTexture;

void main() {
    colour = texture(myTexture, uv);
    
    if (colour.w < 0.1) {
        discard;
    }
}