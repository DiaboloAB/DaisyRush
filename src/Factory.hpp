/*
** EPITECH PROJECT, 2024
** DaisyRush
** File description:
** Factory
*/

#ifndef FACTORY_HPP_
#define FACTORY_HPP_

#include "Core.hpp"
#include "components/BoxCollider.hpp"
#include "components/Transform.hpp"

class Factory {
    public:
        Factory() {};
        ~Factory() {};

        entt::entity createObject(entt::registry &registry, std::string type) {
            if (type == "boxCollider") {
                return createboxCollider(registry);
            } else if (type == "player") {
                return createPlayer(registry);
            } else {
                return entt::null;
            }
        }

    protected:
    private:
        entt::entity createboxCollider(entt::registry &registry) {
            auto entity = registry.create();
            registry.emplace<TransformComponent>(entity);
            registry.emplace<BoxColliderComponent>(entity, entity,
                registry.get<TransformComponent>(entity)._position);
            return entity;
        };
        entt::entity createPlayer(entt::registry &registry) {
            auto entity = registry.create();
            registry.emplace<TransformComponent>(entity);
            registry.emplace<RigidBodyComponent>(entity);
            registry.emplace<BoxColliderComponent>(entity, entity,
                registry.get<TransformComponent>(entity)._position);
            registry.emplace<CameraComponent>(entity);
            registry.emplace<PlayerComponent>(entity, registry, entity);
            registry.get<TransformComponent>(entity)._position = {0, 25, 0};
            return entity;
        };
};

#endif /* !FACTORY_HPP_ */
