//
// Created by manfred on 15-9-14.
//

#ifndef MODERN_OPENGL_SHADER_H
#define MODERN_OPENGL_SHADER_H


#include <string>
#include <GL/glew.h>

class Shader {
public:
	Shader(const std::string& fileName);

	void Bind();

	virtual ~Shader();

private:
	static const unsigned int NUM_SHADERS = 2;
	Shader(const Shader& other){}
	void operator=(const Shader& other){}

	GLuint m_program;   // handle to shader program
	GLuint m_shaders[NUM_SHADERS];
};


#endif //MODERN_OPENGL_SHADER_H
