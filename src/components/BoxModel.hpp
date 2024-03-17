/*
** EPITECH PROJECT, 2024
** DaisyRush
** File description:
** BoxModel
*/

#ifndef BOXMODEL_HPP_
#define BOXMODEL_HPP_

#include "../Core.hpp"

struct BoxModelComponent {

    BoxModelComponent(const std::string &path, const std::string &texturePath)
    {
    }
    ~BoxModelComponent();

    Vector3 _offset;
    Vector3 _size;

    void draw(entt::registry &registry, entt::entity entity)
    {
        auto &transform = registry.get<TransformComponent>(entity);
        DrawCube(transform._position + _offset, _size.x, _size.y, _size.z, RED);
    }
};

#endif /* !BOXMODEL_HPP_ */
