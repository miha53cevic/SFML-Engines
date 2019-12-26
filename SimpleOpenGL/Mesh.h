#pragma once
#include <vector>
#include <gl/glew.h>
#include <memory>

class Mesh
{
public:
    Mesh(const std::vector<GLfloat>& data, const std::vector<GLuint>& indicies);
    ~Mesh();

    void Draw();
    void addTexture(const std::string path, const std::vector<GLfloat>& textureCoords);
    void addNormals(const std::vector<GLfloat>& normals);

    void addData(std::vector<GLfloat>& data, GLuint attributeID, GLuint size);

    GLuint getVAO() const;
    GLuint getTexture() const;
    int    getVertexCount() const;

private:
    void createVAO();
    void unbindVAO();

    void bindIndiciesBuffer(const std::vector<GLuint>& indicies);
    void storeDataInAttributeList(GLuint attributeID, GLuint size, const std::vector<GLfloat>& data);

    GLuint m_VAO;
    std::vector<GLuint> m_VBOs;

    int m_vertexCount;

    GLuint m_TextureID;
    std::vector<GLuint> m_textures;
    void loadTexture(std::string fileName);
};

typedef std::unique_ptr<Mesh> MeshRef;



