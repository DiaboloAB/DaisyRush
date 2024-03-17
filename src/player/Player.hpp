/*
** EPITECH PROJECT, 2024
** DaisyRush
** File description:
** Player
*/

#ifndef PLAYER_HPP_
#define PLAYER_HPP_

#include "../components/Camera.hpp"
#include "../components/Transform.hpp"
#include "../components/RigidBody.hpp"
#include "../components/BoxCollider.hpp"

struct PlayerComponent {

    PlayerComponent(entt::registry& registry, entt::entity entity)
        : _registry(registry), _entity(entity) {
        _speed = 5;
        _speedMultiplier = 1;
        _jumpForce = 10;
    };

    ~PlayerComponent() {};

    void update();

    entt::registry& _registry;
    entt::entity _entity;
    bool _isGrounded;
    float _speed;
    float _speedMultiplier;
    float _jumpForce;
};

#endif /* !PLAYER_HPP_ */
