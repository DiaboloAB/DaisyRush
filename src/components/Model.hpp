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

    ModelComponent(const std::string &path, const std::string &texturePath = "")
    {
        _model = LoadModel(path.c_str());
        if (texturePath != "")
            _model.materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = LoadTexture(texturePath.c_str());
        _scale = 1.0f;
    }
    ~ModelComponent();

    Vector3 _position;
    Vector3 _rotation;
    Vector3 _offset;
    float _scale;

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
        DrawModel(_model, transform._position, _scale, WHITE);
    }

    Model _model;
    Texture2D _texture;
};

#endif /* !MODEL_HPP_ */
