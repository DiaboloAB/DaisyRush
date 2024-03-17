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

void Player::update() {
    auto& position = _registry.get<TransformComponent>(_entity)._position;
    Vector3 dir = {0, 0, 0};

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
    if (IsKeyDown(KEY_SPACE)) {
        position.y += 10 * GetFrameTime();
    }
    if (IsKeyDown(KEY_LEFT_SHIFT)) {
        position.y -= 10 * GetFrameTime();
    }

    float playerAngle = -_registry.get<TransformComponent>(_entity)._rotation.y * DEG2RAD;
    Vector3 rotatedDir = {0};
    rotatedDir.x = dir.x * cos(playerAngle) + dir.z * sin(playerAngle);
    rotatedDir.y = dir.y;
    rotatedDir.z = -dir.x * sin(playerAngle) + dir.z * cos(playerAngle);
    position.x += rotatedDir.x * 10 * GetFrameTime();
    position.z += rotatedDir.z * 10 * GetFrameTime();

    _camera.setCamera3DPosition(position);

    PlayerController::rotate(*this, _registry);
    _camera.setCamera3DRotation(_registry.get<TransformComponent>(_entity)._rotation);
}