/*
** EPITECH PROJECT, 2024
** DaisyRush
** File description:
** RigidBody
*/

#ifndef RIGIDBODY_HPP_
#define RIGIDBODY_HPP_

#include "../Core.hpp"
#include "BoxCollider.hpp"

enum class RigidBodyType {
    STATIC,
    DYNAMIC
};

struct RigidBodyComponent {
    RigidBodyComponent(RigidBodyType type = RigidBodyType::STATIC, float jumpForce = 0, float speed = 0)
        : _type(type), _jumpForce(jumpForce), _speed(speed) {
        _velocity = {0, 0, 0};
        _gravity = -9.81f;
    };
    ~RigidBodyComponent() {};

    Vector3 _velocity;
    RigidBodyType _type;
    float _gravity;
    float _jumpForce;
    float _speed;

    void update(entt::registry &_registry, entt::entity parentEntity) {
        BoxColliderComponent &collider = _registry.get<BoxColliderComponent>(parentEntity);
        TransformComponent &transform = _registry.get<TransformComponent>(parentEntity);


        transform._position.y += _velocity.y * 25 * GetFrameTime();
        if (collider.isColliding(_registry)) {
            transform._position.y -= _velocity.y * GetFrameTime();
        }

        transform._position.x += _velocity.x * GetFrameTime();
        if (collider.isColliding(_registry)) {
            transform._position.x -= _velocity.x * GetFrameTime();
        }

        transform._position.z += _velocity.z * GetFrameTime();
        if (collider.isColliding(_registry)) {
            transform._position.z -= _velocity.z * GetFrameTime();
        }
        _velocity.y += _gravity * GetFrameTime();
        if (_velocity.y < -2.81f) {
            _velocity.y = -2.81f;
        }

    }
};

#endif /* !RIGIDBODY_HPP_ */
