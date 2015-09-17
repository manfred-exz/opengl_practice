//
// Created by manfred on 15-9-17.
//

#ifndef MODERN_OPENGL_TEXTURE_H
#define MODERN_OPENGL_TEXTURE_H

#include <string>
#include <GL/glew.h>

class Texture {
public:
    Texture(const std::string& fileName);

    void Bind(unsigned int unit);

    virtual ~Texture();

private:
    GLuint m_texture;
};


#endif //MODERN_OPENGL_TEXTURE_H
