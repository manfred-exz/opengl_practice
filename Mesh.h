//
// Created by manfred on 15-9-15.
//

#ifndef MODERN_OPENGL_MESH_H
#define MODERN_OPENGL_MESH_H

#include <glm/glm.hpp>
#include <GL/glew.h>

class Vertex{
public:
	Vertex(const glm::vec3&_pos, const glm::vec2& _texCoord){
		this->pos = _pos;
		this->texCoord = _texCoord;
	}
private:
	glm::vec3 pos;
	glm::vec2 texCoord;

	friend class Mesh;
};

class Mesh {
public:
	Mesh(Vertex* vertices, unsigned int numVertices);

	void Draw();

	virtual ~Mesh();

private:
//	Mesh(const Mesh& other);
//	void operator=(const Mesh& other);

	enum{
		POSITION_VB,
		TEXCOORD_VB,
		NUM_BUFFERS
	};

	GLuint m_vertexArrayObject;
	GLuint m_vertexArrayBuffer[NUM_BUFFERS];
	unsigned int m_drawCount;
};


#endif //MODERN_OPENGL_MESH_H
