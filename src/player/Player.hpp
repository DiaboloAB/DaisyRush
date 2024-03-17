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
#include "../plant/Drop.hpp"

struct PlayerComponent {

    PlayerComponent(entt::registry& registry, entt::entity entity)
        : _registry(registry), _entity(entity) {
        _speed = 5;
        _speedMultiplier = 1;
        _jumpForce = 3;
    };

    ~PlayerComponent() {};

    void update();

    void createDrop() {
        auto entity = _registry.create();
        _registry.emplace<TransformComponent>(entity);
        _registry.emplace<RigidBodyComponent>(entity);
        _registry.emplace<BoxColliderComponent>(entity, entity,
            _registry.get<TransformComponent>(entity)._position);
        _registry.emplace<DropComponent>(entity);
        Vector3 dir = {0, 0, 0};
        float playerAngle = _registry.get<TransformComponent>(_entity)._rotation.y;
        dir.x = cos(playerAngle * DEG2RAD) * 25;
        dir.z = sin(playerAngle * DEG2RAD) * 25;
        Vector3 pos = _registry.get<TransformComponent>(_entity)._position;
        _registry.get<TransformComponent>(entity)._position = { pos.x, pos.y - 0.5f, pos.z };
        _registry.get<RigidBodyComponent>(entity)._velocity = dir;
        _registry.get<RigidBodyComponent>(entity)._type = RigidBodyType::DYNAMIC;
        _registry.get<BoxColliderComponent>(entity)._isTrigger = true;
    };

    entt::registry& _registry;
    entt::entity _entity;
    bool _isGrounded;
    float _speed;
    float _speedMultiplier;
    float _jumpForce;
};

#endif /* !PLAYER_HPP_ */
