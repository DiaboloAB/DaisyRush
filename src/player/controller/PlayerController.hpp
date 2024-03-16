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
        static void rotate(Player &player ,Core &core, entt::registry &registry) {
            auto& rotation = registry.get<Rotation>(player.getEntity());
            auto& position = registry.get<Position>(player.getEntity());
            rotation.x += -GetMouseDelta().y * 0.1f;
            rotation.y += GetMouseDelta().x * 0.1f;
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
