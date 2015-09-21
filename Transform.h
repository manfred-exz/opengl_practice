//
// Created by manfred on 15-9-21.
//

#ifndef MODERN_OPENGL_TRANSFORM_H
#define MODERN_OPENGL_TRANSFORM_H

#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>


class Transform {
public:
    Transform(const glm::vec3 &pos = glm::vec3(), const glm::vec3 &rot = glm::vec3(),
              const glm::vec3 &scale = glm::vec3(1.0)) :
            m_pos(pos), m_rot(rot), m_scale(scale) { }


    inline glm::mat4 getModel() const {
        auto posMatrix = glm::translate(m_pos);
        auto scaleMatrix = glm::scale(m_scale);
        auto rotXMatrix = glm::rotate(m_rot.x, glm::vec3(1, 0, 0));
        auto rotYMatrix = glm::rotate(m_rot.y, glm::vec3(0, 1, 0));
        auto rotZMatrix = glm::rotate(m_rot.z, glm::vec3(0, 0, 1));

        /* do the rotation matrix in (x, y, z) order */
        auto rotMatrix = rotZMatrix * rotYMatrix * rotXMatrix;

        return posMatrix * rotMatrix * scaleMatrix;
    }

    inline glm::vec3 &getPos() {
        return m_pos;
    }

    void setScale(const glm::vec3 &scale) {
        m_scale = scale;
    }

    inline glm::vec3 &getRot() {
        return m_rot;
    }

    inline glm::vec3 &getScale() {
        return m_scale;
    }

private:
    glm::vec3 m_pos;
    glm::vec3 m_rot;
    glm::vec3 m_scale;
};


#endif //MODERN_OPENGL_TRANSFORM_H
