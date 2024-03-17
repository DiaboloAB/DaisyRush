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
#include "components/BoxModel.hpp"
#include "components/Transform.hpp"
#include "plant/Plant.hpp"

class Factory {
    public:
        Factory() {};
        ~Factory() {};

        entt::entity createObject(entt::registry &registry, std::string type) {
            if (type == "boxCollider") {
                return createboxCollider(registry);
            } else if (type == "player") {
                return createPlayer(registry);
            } else if (type == "plant") {
                return createPlant(registry);
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
            registry.emplace<BoxModelComponent>(entity);
            return entity;
        };
        entt::entity createPlayer(entt::registry &registry) {
            auto entity = registry.create();
            registry.emplace<TransformComponent>(entity);
            registry.emplace<RigidBodyComponent>(entity);
            registry.emplace<BoxColliderComponent>(entity, entity,
                registry.get<TransformComponent>(entity)._position);
            registry.get<BoxColliderComponent>(entity)._size = {1, 3, 1};
            registry.emplace<CameraComponent>(entity);
            registry.emplace<PlayerComponent>(entity, registry, entity);
            registry.get<TransformComponent>(entity)._position = {0, 40, 0};
            registry.get<TransformComponent>(entity)._rotation = {0, 50, 0};
            return entity;
        };
        entt::entity createPlant(entt::registry &registry) {
            auto entity = registry.create();
            registry.emplace<TransformComponent>(entity);
            registry.emplace<BoxColliderComponent>(entity, entity,
                registry.get<TransformComponent>(entity)._position);
            registry.emplace<PlantComponent>(entity);
            return entity;
        };
};

#endif /* !FACTORY_HPP_ */
