/*
** EPITECH PROJECT, 2024
** DaisyRush
** File description:
** Player
*/

#include "../Core.hpp"
#include "controller/PlayerController.hpp"
#include <cmath>

Vector3 Vector3RotateY(Vector3 v, float angle)
{
    float x = v.x * cos(angle) + v.z * sin(angle);
    float y = v.y;
    float z = -v.x * sin(angle) + v.z * cos(angle);
    return (Vector3){x, y, z};
}

bool checkGround(entt::registry &registry, entt::entity entity)
{
    auto &boxCollider = registry.get<BoxColliderComponent>(entity);
    boxCollider._parentPosition.y -= 1;

    if (boxCollider.isColliding(registry)) {
        boxCollider._parentPosition.y += 1;
        return true;
    }
    return false;
}

void PlayerComponent::update() {
    auto& rigidBody = _registry.get<RigidBodyComponent>(_entity);
    auto& position = _registry.get<TransformComponent>(_entity)._position;
    Vector3 dir = {0, 0, 0};
    std::cout << "position: " << position.x << " " << position.y << " " << position.z << std::endl;
    if (checkGround(_registry, _entity)) {
        _isGrounded = true;
    } else {
        _isGrounded = false;
    }
    std::cout << "grounded: "<< _isGrounded << std::endl;
    if (_isGrounded) {
        rigidBody._velocity.y = 0;
        auto& rigidBody = _registry.get<RigidBodyComponent>(_entity);
        if (IsKeyDown(KEY_SPACE)) {
            rigidBody._velocity.y = rigidBody._jumpForce;
        }
    }

    if (IsKeyDown(KEY_W)) {
        dir.x += 1;
    }
    if (IsKeyDown(KEY_S)) {
        dir.x -= 1;
    }
    if (IsKeyDown(KEY_A)) {
        dir.z -= 1;
    }
    if (IsKeyDown(KEY_D)) {
        dir.z += 1;
    }
    CameraComponent &camera = _registry.get<CameraComponent>(_entity);
    if (IsKeyDown(KEY_LEFT_SHIFT) && IsKeyDown(KEY_W)) {
        if (_speedMultiplier == 2) {
            camera._camera.fovy += 1 * GetFrameTime() * 75;
            if (camera._camera.fovy > 100) {
                camera._camera.fovy = 100;
            }
        }
        _speedMultiplier = 2;
    } else {
        if (_speedMultiplier == 1) {
            camera._camera.fovy -= 1 * GetFrameTime() * 75;
            if (camera._camera.fovy < 90) {
                camera._camera.fovy = 90;
            }
        }
        _speedMultiplier = 1;
    }
    // if (IsKeyDown(KEY_SPACE)) {
    //     position.y += 10 * GetFrameTime();
    // }
    // if (IsKeyDown(KEY_LEFT_SHIFT)) {
    //     position.y -= 10 * GetFrameTime();
    // }

    float playerAngle = -_registry.get<TransformComponent>(_entity)._rotation.y * DEG2RAD;
    Vector3 rotatedDir = {0};
    rotatedDir.x = dir.x * cos(playerAngle) + dir.z * sin(playerAngle);
    rotatedDir.z = -dir.x * sin(playerAngle) + dir.z * cos(playerAngle);

    rigidBody._velocity.x = rotatedDir.x * 500 * _speed * _speedMultiplier * GetFrameTime();
    rigidBody._velocity.z = rotatedDir.z * 500 * _speed * _speedMultiplier * GetFrameTime();

    rigidBody.update(_registry, _entity);

    camera._camera.position = position;

    // if (_registry.get<BoxColliderComponent>(_entity).isColliding(_registry)) {
    //     std::cout << "COLLIDING" << std::endl;
    //     position.x -= rotatedDir.x * 10 * GetFrameTime();
    //     position.z -= rotatedDir.z * 10 * GetFrameTime();
    // }

    PlayerController::rotate(*this, _registry);
    camera.setCamera3DRotation(_registry.get<TransformComponent>(_entity)._rotation);
}