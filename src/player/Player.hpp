/*
** EPITECH PROJECT, 2024
** DaisyRush
** File description:
** Player
*/

#ifndef PLAYER_HPP_
#define PLAYER_HPP_

#include "camera/Cam.hpp"
#include "../components/Transform.hpp"
#include "../components/RigidBody.hpp"
#include "../components/BoxCollider.hpp"
#include "Definition.hpp"

class Player {
    public:

        Player(entt::registry& registry)
            : _registry(registry), _camera(0.0f, 0.0f, 0.0f) {

            _entity = _registry.create();
            _registry.emplace<TransformComponent>(_entity);
            _registry.emplace<RigidBodyComponent>(_entity);
            _registry.emplace<BoxColliderComponent>(_entity);
            _registry.get<TransformComponent>(_entity)._position = {0, 10, 0};

        }

        ~Player() {
            _registry.destroy(_entity);
        }

        void update();
        Cam getCamera3D() { return _camera; }
        entt::entity& getEntity() { return _entity; }
    private:
        entt::registry& _registry;
        entt::entity _entity;
        Cam _camera;
};

#endif /* !PLAYER_HPP_ */
