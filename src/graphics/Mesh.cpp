#include <glad/glad.h>
#include <graphics/gldb.hpp>

#include <graphics/Mesh.hpp>

using graphics::Mesh;

void Mesh::moveFrom(Mesh& src) {
    vao = src.vao;
    vbo = src.vbo;
    ebo = src.ebo;
    numOfIndices = src.numOfIndices;
    
    // Remove the previous values, because ownership has been moved
    src.vao = 0;
    src.vbo = 0;
    src.ebo = 0;
    src.numOfIndices = 0;
}

void Mesh::destroy() {
    glCall(glDeleteVertexArrays, 1, &vao);
    glCall(glDeleteBuffers, 1, &vbo);
    glCall(glDeleteBuffers, 1, &ebo);
}

Mesh::Mesh(): vao(0), vbo(0), ebo(0), numOfIndices(0) {
    
}

Mesh::Mesh(std::vector<Vertex> vertices, std::vector<unsigned int> indices): numOfIndices(indices.size()) {
    glCall(glGenVertexArrays, 1, &vao);
    glCall(glBindVertexArray, vao);
    
    glCall(glGenBuffers, 1, &vbo);
    glCall(glBindBuffer, GL_ARRAY_BUFFER, vbo);
    glCall(glBufferData, GL_ARRAY_BUFFER, vertices.size() * sizeof(vertices[0]), vertices.data(), GL_STATIC_DRAW);
    
    glCall(glGenBuffers, 1, &ebo);
    glCall(glBindBuffer, GL_ELEMENT_ARRAY_BUFFER, ebo);
    glCall(glBufferData, GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(indices[0]), indices.data(), GL_STATIC_DRAW);
    
    glCall(glVertexAttribPointer, 0, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, pos));
    glCall(glEnableVertexAttribArray, 0);
    glCall(glVertexAttribPointer, 1, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, uv));
    glCall(glEnableVertexAttribArray, 1);
    
    glCall(glBindVertexArray, 0);
}

Mesh::Mesh(Mesh& src): numOfIndices(src.numOfIndices) {
    glCall(glGenVertexArrays, 1, &vao);
    glCall(glBindVertexArray, vao);
    
    // Create the vbo
    glCall(glGenBuffers, 1, &vbo);
    glCall(glBindBuffer, GL_ARRAY_BUFFER, vbo);
    
    // Obtain the size of the source vbo's size
    glCall(glBindBuffer, GL_COPY_READ_BUFFER, src.vbo);
    int vboSize;
    glCall(glGetBufferParameteriv, GL_COPY_READ_BUFFER, GL_BUFFER_SIZE, &vboSize);
    
    // Copy the data from the source vbo to our vbo
    glCall(glBufferData, GL_ARRAY_BUFFER, vboSize, nullptr, GL_STATIC_DRAW);
    glCall(glCopyBufferSubData, GL_COPY_READ_BUFFER, GL_ARRAY_BUFFER, 0, 0, vboSize);
    
    // Unbind the source vbo
    glCall(glBindBuffer, GL_COPY_READ_BUFFER, 0);
    
    // Do the same for the ebo
    glCall(glGenBuffers, 1, &ebo);
    glCall(glBindBuffer, GL_ELEMENT_ARRAY_BUFFER, ebo);
    glCall(glBindBuffer, GL_COPY_READ_BUFFER, src.ebo);
    int eboSize;
    glCall(glGetBufferParameteriv, GL_COPY_READ_BUFFER, GL_BUFFER_SIZE, &eboSize);
    glCall(glBufferData, GL_ELEMENT_ARRAY_BUFFER, eboSize, nullptr, GL_STATIC_DRAW);
    glCall(glCopyBufferSubData, GL_COPY_READ_BUFFER, GL_ELEMENT_ARRAY_BUFFER, 0, 0, eboSize);
    glCall(glBindBuffer, GL_COPY_READ_BUFFER, 0);
    
    // #@
    glCall(glVertexAttribPointer, 0, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, pos));
    glCall(glEnableVertexAttribArray, 0);
    glCall(glVertexAttribPointer, 1, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, uv));
    glCall(glEnableVertexAttribArray, 1);
    
    glCall(glBindVertexArray, 0);
}

Mesh& Mesh::operator=(Mesh& rhs) {
    Mesh newSprite(rhs);
    swap(*this, newSprite);
    return *this;
}

Mesh::Mesh(Mesh&& src) {
    moveFrom(src);
}

Mesh& Mesh::operator=(Mesh&& rhs) {
    destroy();
    moveFrom(rhs);
    return *this;
}

void Mesh::render() {
    glCall(glBindVertexArray, vao);
    glCall(glDrawElements, GL_TRIANGLES, numOfIndices, GL_UNSIGNED_INT, nullptr);
    glCall(glBindVertexArray, 0);
}

void Mesh::swap(Mesh& a, Mesh& b) {
    std::swap(a.vao, b.vao);
    std::swap(a.vbo, b.vbo);
    std::swap(a.ebo, b.ebo);
    
    std::swap(a.numOfIndices, b.numOfIndices);
}

Mesh::~Mesh() {
    destroy();
}