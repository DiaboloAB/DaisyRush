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
                auto entity = registry.create();
                registry.emplace<BoxColliderComponent>(entity);
                registry.emplace<TransformComponent>(entity);
                return entity;
            }
            throw std::runtime_error("Unknown type");
        };
    protected:
    private:
};

#endif /* !FACTORY_HPP_ */
