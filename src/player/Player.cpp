/*
** EPITECH PROJECT, 2024
** DaisyRush
** File description:
** Player
*/

#include "Player.hpp"
#include "controller/PlayerController.hpp"
#include <cmath>

Vector3 Vector3RotateY(Vector3 v, float angle)
{
    float x = v.x * cos(angle) + v.z * sin(angle);
    float y = v.y;
    float z = -v.x * sin(angle) + v.z * cos(angle);
    return (Vector3){x, y, z};
}

void Player::update(Core &core) {
    auto& position = _registry.get<Position>(_entity);
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
        position.y += 1;
    }
    if (IsKeyDown(KEY_LEFT_SHIFT)) {
        position.y -= 1;
    }

    std::cout << "Player Angle: " << _registry.get<Rotation>(_entity).y << std::endl;
    float playerAngle = -_registry.get<Rotation>(_entity).y * DEG2RAD;
    std::cout << "Player Angle: " << playerAngle << std::endl;
    std::cout << "Dir: " << dir.x << " " << dir.y << " " << dir.z << std::endl;
    Vector3 rotatedDir = {0};
    rotatedDir.x = dir.x * cos(playerAngle) + dir.z * sin(playerAngle);
    rotatedDir.y = dir.y;
    rotatedDir.z = -dir.x * sin(playerAngle) + dir.z * cos(playerAngle);
    std::cout << "Rotated Dir: " << rotatedDir.x << " " << rotatedDir.y << " " << rotatedDir.z << std::endl;
    position.x += rotatedDir.x * 1;
    position.z += rotatedDir.z * 1;

    _camera.setCamera3DPosition(position.x, position.y, position.z);

    PlayerController::rotate(*this, core, _registry);
    _camera.setCamera3DRotation(_registry.get<Rotation>(_entity).x, _registry.get<Rotation>(_entity).y, _registry.get<Rotation>(_entity).z);
}