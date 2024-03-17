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
#include "Menu.hpp"
#include "map/Map.hpp"
#include "scoreboard/Scoreboard.hpp"

enum class SceneType {
    MENU,
    GAME,
    QUIT
};
class Core {
    public:
        Core(entt::registry &registry, Scoreboard _scoreboard) : _registry(registry), _map(registry), _scoreboard(_scoreboard) {
            InitWindow(1920, 1080, "Draw OBJ Example");
            SetTargetFPS(60);
            DisableCursor();
            ToggleFullscreen();
            _player = _factory.createObject(_registry, "player");
            _model = LoadModel("assets/flower.obj");
            _texture = LoadTexture("assets/flower.png");
            _model.materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = _texture;
            _can = LoadTexture("assets/can.png");
            _can.height *= 6;
            _can.width *= 6;
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


        void menuLoop()
        {

            while (!WindowShouldClose()) {
                if (IsKeyPressed(KEY_ENTER)) {
                    _scene = SceneType::GAME;
                    return;
                }
                _menu._fontSizeSin += 0.1f;
                BeginDrawing();
                ClearBackground(SKYBLUE);
                DrawText("Welcome to DaisyRush", 200, 100, 50, WHITE);
                DrawText("Press Enter to start", 200, 200, 25 + sin(_menu._fontSizeSin) * 3, WHITE);
                int i = 0;
                for (auto &el: _scoreboard.getScores()) {
                    i++;
                    std::string str = std::get<0>(el) + "        ";
                    str += std::to_string((float)((float)std::get<1>(el) / 1000.0)) + " seconds";
                    const char *cstr = str.c_str();
                    DrawText(cstr, 200 , 300 + i * 25, 25, WHITE);
                }
                EndDrawing();
            }
            _scene = SceneType::QUIT;
        }

        void gameLoop()
        {
            while (!WindowShouldClose()) {
                if (IsKeyPressed(KEY_ESCAPE)) {
                    _scene = SceneType::MENU;
                    return;
                }
                if (IsKeyDown(KEY_W)) {
                    if (_registry.get<PlayerComponent>(_player)._speedMultiplier < 2.0f)
                        _canMovement += 0.225f;
                    else
                        _canMovement += 0.35f;
                }
                _registry.get<PlayerComponent>(_player).update();
                BeginDrawing();
                ClearBackground(BLUE);
                BeginMode3D(_registry.get<CameraComponent>(_player)._camera);
                DrawModel(_model, {0.0f, 20.0f, 0.0f}, 1.0f, WHITE);
                _map.draw(_registry);
                // DrawGrid(1000, 10.0f);
                if (_debug) {
                    drawColliders();
                }
                EndMode3D();
                DrawTexture(_can, _screenWidth - 900, _screenHeight - 550 + sin(_canMovement) * 15, WHITE);
                EndDrawing();
            }
            _scene = SceneType::QUIT;
        }

        void run() {
            while (!WindowShouldClose()) {
                if (_scene == SceneType::MENU) {
                    menuLoop();
                } else if (_scene == SceneType::GAME) {
                    gameLoop();
                } else {
                    break;
                }
            }
            
        }

    protected:
    private:
        entt::entity _player;
        int _screenWidth = 1920;
        int _screenHeight = 1080;
        entt::registry &_registry;
        Model _model;
        Texture2D _texture;
        Factory _factory;
        Texture2D _can;
        float _canMovement;

        bool _debug = false;
        Menu _menu;
        SceneType _scene = SceneType::MENU;
        Map _map;
        Scoreboard _scoreboard;
};

#endif /* !CORE_HPP_ */
