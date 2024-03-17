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

    BoxModelComponent(Vector3 size = { 1.0f, 1.0f, 1.0f }, Vector3 offset = { 0, 0, 0 })
        : _offset(offset), _size(size)
    {
    }
    ~BoxModelComponent() {};

    Vector3 _offset;
    Vector3 _size;

    void draw(entt::registry &registry, entt::entity entity)
    {
        auto &transform = registry.get<TransformComponent>(entity);

        DrawCube({
            transform._position.x + _offset.x,
            transform._position.y + _offset.y,
            transform._position.z + _offset.z
        }, _size.x, _size.y, _size.z, DARKGREEN);
        DrawCubeWires({
            transform._position.x + _offset.x,
            transform._position.y + _offset.y,
            transform._position.z + _offset.z
        }, _size.x, _size.y, _size.z, BLACK);
    }
};

#endif /* !BOXMODEL_HPP_ */
