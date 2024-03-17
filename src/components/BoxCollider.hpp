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
    BoxColliderComponent(entt::entity parentEntity, Vector3 &parentPosition, Vector3 size = {1, 1, 1}, Vector3 offset = {0, 0, 0})
        : _size(size), _offset(offset), _parentEntity(parentEntity), _parentPosition(parentPosition) {};
    ~BoxColliderComponent() {};

    Vector3 _size;
    Vector3 _offset;
    Vector3 &_parentPosition;
    entt::entity _parentEntity;
    bool _isTrigger = false;
    std::string _tag = "Untagged";

    std::vector<BoxColliderComponent> _collisions;

    bool checkCollision(BoxColliderComponent &other) {
        Vector3 otherPos = {other._parentPosition.x - other._size.x / 2, other._parentPosition.y - other._size.y / 2, other._parentPosition.z - other._size.z / 2};

        Vector3 pos = {_parentPosition.x - _size.x / 2, _parentPosition.y - _size.y / 2, _parentPosition.z - _size.z / 2};

        if (pos.x + _size.x > otherPos.x &&
            pos.x < otherPos.x + other._size.x &&
            pos.y + _size.y > otherPos.y &&
            pos.y < otherPos.y + other._size.y &&
            pos.z + _size.z > otherPos.z &&
            pos.z < otherPos.z + other._size.z) {
            return true;
        }
        return false;
    }

    bool isColliding(entt::registry &_registry) {
        auto view = _registry.view<BoxColliderComponent>();
        for (auto entity : view) {
            if (entity != _parentEntity) {
                auto& other = view.get<BoxColliderComponent>(entity);
                if (!other._isTrigger && checkCollision(other)) {
                    _collisions.push_back(other);
                    return true;
                }
            }
        }
        return false;
    }

    bool isTriggering(entt::registry &_registry) {
        auto view = _registry.view<BoxColliderComponent>();
        for (auto entity : view) {
            if (entity != _parentEntity) {
                auto& other = view.get<BoxColliderComponent>(entity);
                if (other._isTrigger && checkCollision(other)) {
                    _collisions.push_back(other);
                    return true;
                }
            }
        }
        return false;
    }
};

#endif /* !BOXCOLLIDER_HPP_ */
