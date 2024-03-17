/*
** EPITECH PROJECT, 2024
** DaisyRush
** File description:
** Drop
*/

#ifndef DROP_HPP_
#define DROP_HPP_

#include "../Core.hpp"

struct DropComponent {

    DropComponent() { _lifeTime = 3;};
    ~DropComponent() {};

    void update(entt::registry &registry, entt::entity drop) {
        auto &rigidBody = registry.get<RigidBodyComponent>(drop);
        rigidBody.update(registry, drop);
        _lifeTime -= GetFrameTime();
    }

    void draw(entt::registry &registry, entt::entity drop) {
        auto &transform = registry.get<TransformComponent>(drop);
        DrawCube(transform._position, 1, 1, 1, Fade(BLUE, 0.5f));
    }

    float _lifeTime;
};

#endif /* !DROP_HPP_ */
