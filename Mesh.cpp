//
// Created by manfred on 15-9-15.
//
#include <iostream>
#include <vector>
#include "Mesh.h"

using namespace std;


Mesh::Mesh(Vertex *vertices, unsigned int numVertices) {
	m_drawCount = numVertices;
	std::cout << numVertices << " vertices is going to be drawn. " << std::endl;

	glGenVertexArrays(1, &m_vertexArrayObject);
	glBindVertexArray(m_vertexArrayObject);

	std::vector<glm::vec3> positions;
	std::vector<glm::vec2> texCoords;

	positions.reserve(numVertices);
	texCoords.reserve(numVertices);

	for(unsigned int i = 0; i < numVertices; ++i){
		positions.push_back(vertices[i].pos);
		texCoords.push_back(vertices[i].texCoord);
	}


	/* allocate buffer, declare buffer type, init it with data */
	glGenBuffers(NUM_BUFFERS, m_vertexArrayBuffer);


	glBindBuffer(GL_ARRAY_BUFFER, m_vertexArrayBuffer[POSITION_VB]);
	// GL_STATIC_DRAW means we don't expect the data to be modified,
	// then gpu can find a better place to store it(optimized.)
	glBufferData(GL_ARRAY_BUFFER, numVertices*sizeof(positions[0]), &positions[0], GL_STATIC_DRAW);

	/* tell opengl within each element of the array('vertices' this time),
	 * how the data is organized. */
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);


	/* allocate buffer, declare buffer type, init it with data */
	glBindBuffer(GL_ARRAY_BUFFER, m_vertexArrayBuffer[TEXCOORD_VB]);
	// GL_STATIC_DRAW means we don't expect the data to be modified,
	// then gpu can find a better place to store it(optimized.)
	glBufferData(GL_ARRAY_BUFFER, numVertices*sizeof(texCoords[0]), &texCoords[0], GL_STATIC_DRAW);

	/* tell opengl within each element of the array('vertices' this time),
	 * how the data is organized. */
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 0, 0);



	glBindVertexArray(0);
}

Mesh::~Mesh() {
	glDeleteVertexArrays(1, &m_vertexArrayObject);
}

void Mesh::Draw() {
	glBindVertexArray(m_vertexArrayObject);
	glDrawArrays(GL_TRIANGLES, 0, m_drawCount);
	glBindVertexArray(0);
}