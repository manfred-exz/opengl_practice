//
// Created by manfred on 15-9-14.
//

#ifndef MODERN_OPENGL_SHADER_H
#define MODERN_OPENGL_SHADER_H


#include <string>
#include <GL/glew.h>
#include "Transform.h"

class Shader {
public:
	Shader(const std::string& fileName);

	void Bind();
	void Update(const Transform& transform);

	virtual ~Shader();

private:
	static const unsigned int NUM_SHADERS = 2;
	Shader(const Shader& other){}
	void operator=(const Shader& other){}

	enum{
		TRANSFORM_U,

		NUM_UNIFORMS,
	};

	GLuint m_program;   // handle to shader program
	GLuint m_shaders[NUM_SHADERS];
	GLint m_uniforms[NUM_UNIFORMS];
};


#endif //MODERN_OPENGL_SHADER_H
