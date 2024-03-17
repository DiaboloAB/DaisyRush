/*
** EPITECH PROJECT, 2024
** DaisyRush
** File description:
** BoxCollider
*/

#ifndef BOXCOLLIDER_HPP_
#define BOXCOLLIDER_HPP_

#include "../Core.hpp"

struct BoxColliderComponent {
    BoxColliderComponent(Vector3 size = {1, 1, 1}, Vector3 offset = {0, 0, 0}, Vector3 position = {0, 0, 0})
        : _size(size), _offset(offset), _position(position) {};
    ~BoxColliderComponent() {};

    Vector3 _size;
    Vector3 _offset;
    Vector3 _position;

    void update(entt::registry &_registry, entt::entity parentEntity) {
        try {
            auto& transform = _registry.get<TransformComponent>(parentEntity);
            _position = transform._position;
        } catch (const std::exception& e) {
            std::cerr << e.what() << std::endl;
        }
    }

    bool checkCollision(BoxColliderComponent &other) {
        if (_position.x + _size.x > other._position.x &&
            _position.x < other._position.x + other._size.x &&
            _position.y + _size.y > other._position.y &&
            _position.y < other._position.y + other._size.y &&
            _position.z + _size.z > other._position.z &&
            _position.z < other._position.z + other._size.z) {
            return true;
        }
        return false;
    }
};

#endif /* !BOXCOLLIDER_HPP_ */
