/*
** EPITECH PROJECT, 2024
** DaisyRush
** File description:
** CamController
*/

#ifndef CAMCONTROLLER_HPP_
#define CAMCONTROLLER_HPP_

#pragma once

#include "../../Core.hpp"

class PlayerController {
    public:
        static void rotate(Player &player, entt::registry &registry) {
            auto& rotation = registry.get<TransformComponent>(player.getEntity())._rotation;
            auto& position = registry.get<TransformComponent>(player.getEntity())._position;
            rotation.x += -GetMouseDelta().y * 3.0f * GetFrameTime();
            rotation.y += GetMouseDelta().x * 3.0f * GetFrameTime();
            if (rotation.x > 89.0f) {
                rotation.x = 89.0f;
            }
            if (rotation.x < -89.0f) {
                rotation.x = -89.0f;
            }
        };
    private:
};

#endif /* !CAMCONTROLLER_HPP_ */
