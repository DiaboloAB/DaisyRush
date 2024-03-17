/*
** EPITECH PROJECT, 2024
** DaisyRush
** File description:
** Model
*/

#ifndef MODEL_HPP_
#define MODEL_HPP_

#include "../Core.hpp"

struct ModelComponent {

    ModelComponent(const std::string &path, const std::string &texturePath)
    {
        _model = LoadModel(path.c_str());
        _texture = LoadTexture(texturePath.c_str());
    }
    ~ModelComponent();

    Vector3 _position;
    Vector3 _offset;
    Vector3 _scale;

    void update(entt::registry &_registry, entt::entity parentEntity) {
        try {
            auto& transform = _registry.get<TransformComponent>(parentEntity);
            _position = transform._position + _offset;
        } catch (const std::exception& e) {
            std::cerr << e.what() << std::endl;
        }
    }

    void draw(entt::registry &registry, entt::entity entity)
    {
        auto &transform = registry.get<TransformComponent>(entity);
        DrawModel(_model, transform._position, 1.0f, WHITE);
    }

    Model _model;
    Texture2D _texture;
};

#endif /* !MODEL_HPP_ */
