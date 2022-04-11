#pragma once

#include <glm/vec3.hpp>
#include <glm/mat4x4.hpp>
#include <glm/gtx/vector_angle.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "input.h"

class Camera
{
public:
    static constexpr float MOVE_SPEED = 0.05f;

    Camera()
        : m_position(1.25f, 0.0f, 0.0f)
        , m_direction(0.0f, 0.0f, -1.0f)
        , m_up(0.0f, 1.0f, 0.0f)
        , m_pitch(0.0f)
        , m_yaw(-90.0f)
    {
    }

    glm::mat4 view_matrix() const
    {
        return glm::lookAt(m_position, m_position + m_direction, m_up);
    }

    void move(const glm::vec2& mouse_position)
    {
        // not working lol
//        float xoffset = mouse_position.x * 0.1f;
//        float yoffset = mouse_position.y * 0.1f;
//
//        m_yaw   += xoffset;
//        m_pitch += yoffset;
//
//        m_pitch = glm::clamp(m_pitch, -89.0f, 89.0f);
//
//        m_direction.x = glm::cos(glm::radians(m_yaw)) * cos(glm::radians(m_pitch));
//        m_direction.y = glm::sin(glm::radians(m_pitch));
//        m_direction.z = glm::sin(glm::radians(m_yaw)) * cos(glm::radians(m_pitch));
//        m_direction = glm::normalize(m_direction);

        if (Input::inst()->down_key(INP_KEY_Q)) // turn left
            m_yaw -= 1.0f;

        if (Input::inst()->down_key(INP_KEY_E)) // turn right
            m_yaw += 1.0f;

        m_direction.x = glm::cos(glm::radians(m_yaw));
        m_direction.z = glm::sin(glm::radians(m_yaw));

        if (Input::inst()->down_key(INP_KEY_W)) // forward
            m_position -= m_direction * MOVE_SPEED;

        if (Input::inst()->down_key(INP_KEY_S)) // backwards
            m_position += m_direction * MOVE_SPEED;

        if (Input::inst()->down_key(INP_KEY_A)) // left
            m_position -= glm::cross(m_direction, m_up) * MOVE_SPEED;

        if (Input::inst()->down_key(INP_KEY_D)) // right
            m_position += glm::cross(m_direction, m_up) * MOVE_SPEED;

        if (Input::inst()->down_key(INP_KEY_SPACE)) // up
            m_position -= m_up * MOVE_SPEED;

        if (Input::inst()->shift()) // down
            m_position += m_up * MOVE_SPEED;
    }

    const glm::vec3& position() const { return m_position; }
    const glm::vec3& direction() const { return m_direction; }
    const glm::vec3& up() const { return m_up; }

private:
    glm::vec3 m_position;
    glm::vec3 m_direction;
    glm::vec3 m_up;

    float m_pitch;
    float m_yaw;
};
