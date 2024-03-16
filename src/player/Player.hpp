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
#include "Definition.hpp"

class Core;
class Player {
    public:

        Player(entt::registry& registry, float startX, float startY, float startZ)
            : _registry(registry), _camera(startX, startY, startZ) {

            _entity = _registry.create();
            _registry.emplace<Position>(_entity, startX, startY, startZ);
            _registry.emplace<Rotation>(_entity, 0.0f, 0.0f, 0.0f);
        }

        ~Player() {
            _registry.destroy(_entity);
        }

        void update(Core &core);
        Cam getCamera3D() { return _camera; }
        entt::entity& getEntity() { return _entity; }
    private:
        entt::registry& _registry;
        entt::entity _entity;
        Cam _camera;
};

#endif /* !PLAYER_HPP_ */
