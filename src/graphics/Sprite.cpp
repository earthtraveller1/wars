#include <glad/glad.h>

#include <graphics/Sprite.hpp>

using wars::graphics::Sprite;

Sprite::Sprite(std::vector<Vertex> vertices, std::vector<uint8_t> indices)
{
    glGenVertexArrays(1, &m_vao);
    glBindVertexArray(m_vao);
    
    glGenBuffers(1, &m_vbo);
    glBindBuffer(GL_ARRAY_BUFFER, m_vbo);
    glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(vertices[0]), vertices.data(), GL_STATIC_DRAW);
    
    glGenBuffers(1, &m_ebo);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_ebo);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(indices[0]), indices.data(), GL_STATIC_DRAW);
    
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), reinterpret_cast<void*>(offsetof(Vertex, m_pos)));
    glEnableVertexAttribArray(0);
    
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), reinterpret_cast<void*>(offsetof(Vertex, m_uv)));
    glEnableVertexAttribArray(1);
    
    glBindVertexArray(0);
}




Sprite::Sprite(Sprite& src)
{
    glGenVertexArrays(1, &m_vao);
    glBindVertexArray(m_vao);
    
    glBindBuffer(GL_READ_BUFFER, src.m_vbo);
    
    uint32_t sourceVBOSize = 0;
    glGetBufferParameteriv(GL_READ_BUFFER, GL_BUFFER_SIZE, reinterpret_cast<GLint*>(&sourceVBOSize));
    glGenBuffers(1, &m_vbo);
    glBindBuffer(GL_ARRAY_BUFFER, m_vbo);
    glBufferData(GL_ARRAY_BUFFER, sourceVBOSize, nullptr, GL_STATIC_DRAW);
    glCopyBufferSubData(GL_READ_BUFFER, GL_ARRAY_BUFFER, 0, 0, sourceVBOSize);
    
    glBindBuffer(GL_READ_BUFFER, src.m_ebo);
    
    uint32_t sourceEBOSize = 0;
    glGetBufferParameteriv(GL_READ_BUFFER, GL_BUFFER_SIZE, reinterpret_cast<GLint*>(&sourceEBOSize));
    glGenBuffers(1, &m_ebo);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_ebo);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sourceEBOSize, nullptr, GL_STATIC_DRAW);
    glCopyBufferSubData(GL_READ_BUFFER, GL_ELEMENT_ARRAY_BUFFER, 0, 0, sourceEBOSize);
    
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), reinterpret_cast<void*>(offsetof(Vertex, m_pos)));
    glEnableVertexAttribArray(0);
    
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), reinterpret_cast<void*>(offsetof(Vertex, m_uv)));
    glEnableVertexAttribArray(1);
    
    glBindVertexArray(0);
}