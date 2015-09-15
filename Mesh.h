//
// Created by manfred on 15-9-15.
//

#ifndef MODERN_OPENGL_MESH_H
#define MODERN_OPENGL_MESH_H

#include <glm/glm.hpp>
#include <GL/glew.h>

class Vertex{
public:
	Vertex(const glm::vec3&_pos){
		this->pos = _pos;
	}
private:
	glm::vec3 pos;
};

class Mesh {
public:
	Mesh(Vertex* vertices, unsigned int numVertices);

	void Draw();

	virtual ~Mesh();

private:
	Mesh(const Mesh& other);
	void operator=(const Mesh& other);

	enum{
		POSITION_VB,

		NUM_BUFFERS
	};

	GLuint m_vertexArrayObject;
	GLuint m_vertexArrayBuffer[NUM_BUFFERS];
	unsigned int m_drawCount;
};


#endif //MODERN_OPENGL_MESH_H
