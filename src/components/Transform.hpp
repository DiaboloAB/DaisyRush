/*
** EPITECH PROJECT, 2024
** DaisyRush
** File description:
** Transform
*/

#ifndef TRANSFORM_HPP_
#define TRANSFORM_HPP_

#include "../Core.hpp"

struct TransformComponent {
    TransformComponent(Vector3 position = {0}, Vector3 rotation = {0}, Vector3 scale = {1, 1, 1})
        : _position(position), _rotation(rotation), _scale(scale) {}
    ~TransformComponent() {};

    Vector3 _position;
    Vector3 _rotation;
    Vector3 _scale;
};

#endif /* !TRANSFORM_HPP_ */
