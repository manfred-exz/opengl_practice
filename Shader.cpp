//
// Created by manfred on 15-9-14.
//

#include <fstream>
#include <iostream>
#include "Shader.h"

using namespace std;

static void CheckShaderError(GLuint shader, GLuint flag, bool isProgram, const string &errorMessage);
static string LoadShader(const string &fileName);
static GLuint CreateShader(const string& text, GLenum shaderType);

Shader::Shader(const string &fileName) {
	m_program = glCreateProgram();
	m_shaders[0] = CreateShader(LoadShader(fileName + ".vs"), GL_VERTEX_SHADER);
	m_shaders[1] = CreateShader(LoadShader(fileName + ".fs"), GL_FRAGMENT_SHADER);

	for(unsigned int i = 0; i < NUM_SHADERS; ++i){
		glAttachShader(m_program, m_shaders[i]);
	}

	glBindAttribLocation(m_program, 0, "position");

	glLinkProgram(m_program);
	CheckShaderError(m_program, GL_LINK_STATUS, true, "Error: Program linking failed: ");

	glValidateProgram(m_program);
	CheckShaderError(m_program, GL_VALIDATE_STATUS, true, "Error: Program is invalid: ");
}

Shader::~Shader() {
	for(unsigned int i = 0; i < NUM_SHADERS; ++i){
		glDetachShader(m_program, m_shaders[i]);
		glDeleteShader(m_shaders[i]);
	}

	glDeleteProgram(m_program);
}


static string LoadShader(const string &fileName) {
	ifstream file;
	file.open(fileName);

	string output, line;

	if (file.is_open()) {
		while (file.good()) {
			getline(file, line);
			output.append(line + "\n");
		}
	}
	else {
		cerr << "Unable to load shader: " << fileName << endl;
	}

	return output;
}


void static CheckShaderError(GLuint shader, GLuint flag, bool isProgram, const string &errorMessage) {
	GLint success = GL_FALSE;
	GLchar error[1024] = {0};

	if (isProgram)
		glGetProgramiv(shader, flag, &success);
	else
		glGetShaderiv(shader, flag, &success);

	if (success == GL_FALSE) {
		if (isProgram)
			glGetProgramInfoLog(shader, sizeof(error), NULL, error);
		else
			glGetShaderInfoLog(shader, sizeof(error), NULL, error);

		cerr << errorMessage << ": '" << error << "'" << endl;
	}
}

GLuint CreateShader(const string &text, GLenum shaderType) {
	GLuint shader = glCreateShader(shaderType);

	if(shader == 0)
		cerr << "Error: Shader creation faild!" << endl;

	const GLchar* shaderSrcStrs[1];
	GLint shaderSrcStrLen[1];

	shaderSrcStrs[0] = text.c_str();
	shaderSrcStrLen[0] = (GLint) text.length();

	glShaderSource(shader, 1, shaderSrcStrs, shaderSrcStrLen);
	glCompileShader(shader);

	CheckShaderError(shader, GL_COMPILE_STATUS, false, "Error: Shader compilation failed!");

	return 0;
}


void Shader::Bind() {
	glUseProgram(m_program);
}