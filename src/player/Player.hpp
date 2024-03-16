/*
** EPITECH PROJECT, 2024
** DaisyRush
** File description:
** Player
*/

#ifndef PLAYER_HPP_
#define PLAYER_HPP_

#include "../Core.hpp"
#include "camera/Cam.hpp"

struct Position {
    float x, y, z;
};

struct Rotation {
    float x, y, z;
};

class Player {
public:

    Player(entt::registry& registry, float startX, float startY, float startZ)
        : _registry(registry), _camera(startX, startY, startZ) {

        _entity = _registry.create();
        _registry.emplace<Position>(_entity, startX, startY, startZ);
        _registry.emplace<Rotation>(_entity, 0, 0, 0);
    }

    ~Player() {
        _registry.destroy(_entity);
    }

    void update();
    Cam getCamera() { return _camera; }
private:
    entt::registry& _registry;
    entt::entity _entity;
    Cam _camera;
};

#endif /* !PLAYER_HPP_ */
