/*
** EPITECH PROJECT, 2024
** DaisyRush
** File description:
** Core
*/

#ifndef CORE_HPP_
#define CORE_HPP_

#include  "../lib/entt/src/entt/entt.hpp"
#include <iostream>
#include "raylib.h"
#include <memory>
#include "player/Player.hpp"
#include "Factory.hpp"
class Core {
    public:
        Core(entt::registry &registry) : _registry(registry) {
            InitWindow(_screenWidth, _screenHeight, "Draw OBJ Example");
            SetTargetFPS(60);
            DisableCursor();
            ToggleFullscreen();
            _screenWidth = GetScreenWidth();
            _screenHeight = GetScreenHeight();

            _player = _factory.createObject(_registry, "player");
            _model = LoadModel("assets/flower.obj");
            _texture = LoadTexture("assets/flower.png");
            _model.materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = _texture;
            entt::entity ground = _factory.createObject(_registry, "boxCollider");
            _registry.get<BoxColliderComponent>(ground)._size = {1000, 10, 1000};
        };
        ~Core() {
            CloseWindow();
        };

        void drawColliders() {
            auto view = _registry.view<BoxColliderComponent, TransformComponent>();
            for (auto entity : view) {
                auto& boxCollider = view.get<BoxColliderComponent>(entity);
                auto& transform = view.get<TransformComponent>(entity);
                DrawCubeWires(transform._position, boxCollider._size.x, boxCollider._size.y, boxCollider._size.z, RED);
            }
        }

        void run() {
            while (!WindowShouldClose()) {
                _registry.get<PlayerComponent>(_player).update();
                BeginDrawing();
                ClearBackground(BLUE);
                BeginMode3D(_registry.get<CameraComponent>(_player)._camera);
                DrawModel(_model, {0.0f, 0.0f, 0.0f}, 1.0f, WHITE);
                if (_debug) {
                    DrawGrid(1000, 10.0f);
                    drawColliders();
                }
                EndMode3D();
                DrawText("(c) Flower 3D model by Alberto Cano", _screenWidth - 200, _screenHeight - 20, 10, GRAY);
                EndDrawing();
            }
        }

    protected:
    private:
        entt::entity _player;
        int _screenWidth = 800;
        int _screenHeight = 450;
        entt::registry &_registry;
        Model _model;
        Texture2D _texture;
        Factory _factory;

        bool _debug = true;
};

#endif /* !CORE_HPP_ */
