/*
** EPITECH PROJECT, 2024
** DaisyRush
** File description:
** RigidBody
*/

#ifndef RIGIDBODY_HPP_
#define RIGIDBODY_HPP_

#include "../Core.hpp"

enum class RigidBodyType {
    STATIC,
    DYNAMIC
};

struct RigidBodyComponent {
    RigidBodyComponent(RigidBodyType type = RigidBodyType::STATIC, float gravity = 0, float jumpForce = 0, float speed = 0)
        : _type(type), _gravity(gravity), _jumpForce(jumpForce), _speed(speed) {
        _velocity = {0, 0, 0};
        _isGrounded = false;
    };
    ~RigidBodyComponent() {};

    Vector3 _velocity;
    RigidBodyType _type;
    bool _isGrounded;
    float _gravity;
    float _jumpForce;
    float _speed;

    void update(entt::registry &_registry, entt::entity parentEntity) {
        try {
            auto& transform = _registry.get<TransformComponent>(parentEntity);
            transform._position.x += _velocity.x * GetFrameTime();
            transform._position.y += _velocity.y * GetFrameTime();
            transform._position.z += _velocity.z * GetFrameTime();
        } catch (const std::exception& e) {
            std::cerr << e.what() << std::endl;
        }
    }
};

#endif /* !RIGIDBODY_HPP_ */
