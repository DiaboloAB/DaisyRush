/*
** EPITECH PROJECT, 2024
** DaisyRush
** File description:
** Player
*/

#include "Player.hpp"

void Player::update() {
    auto& position = _registry.get<Position>(_entity);

    if (IsKeyDown(KEY_W)) {
        position.x += 1;
    }
    if (IsKeyDown(KEY_S)) {
        position.x -= 1;
    }
    if (IsKeyDown(KEY_A)) {
        position.z -= 1;
    }
    if (IsKeyDown(KEY_D)) {
        position.z += 1;
    }
    if (IsKeyDown(KEY_SPACE)) {
        position.y += 1;
    }
    if (IsKeyDown(KEY_LEFT_SHIFT)) {
        position.y -= 1;
    }
    std::cout << "x: " << position.x << " y: " << position.y << std::endl;
    _camera.setCameraPosition(position.x, position.y, position.z);
}