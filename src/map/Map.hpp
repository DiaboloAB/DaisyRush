/*
** EPITECH PROJECT, 2024
** DaisyRush
** File description:
** Map
*/

#ifndef MAP_HPP_
#define MAP_HPP_

#include "../Core.hpp"

class Map {
    public:
        Map(entt::registry &registry) : _registry(registry) {

            createBlock({0, 0, 0}, {10, 10, 10});
            createBlock({15, 0, 0}, {10, 10, 10});

            createBlock({30, 0, 0}, {10, 10, 10});
            createPlant({30, 10, 0});
            createPlant({25, 10, 5});
        };
        ~Map() {};

        void createPlant(Vector3 position) {
            entt::entity plant = _factory.createObject(_registry, "plant");
            _registry.get<PlantComponent>(plant)._position = position;
        }

        void createBlock(Vector3 position, Vector3 size) {
            entt::entity block = _factory.createObject(_registry, "boxCollider");
            _registry.get<TransformComponent>(block)._position = position;
            _registry.get<BoxColliderComponent>(block)._size = size;
            _registry.get<BoxModelComponent>(block)._size = size;
        }

        void drawPlant(entt::registry &registry) {
            auto view = registry.view<TransformComponent, PlantComponent>();
            for (auto entity : view) {
                auto &transform = view.get<TransformComponent>(entity);
                auto &plant = view.get<PlantComponent>(entity);
                plant.draw();
            }
        }

        void drawBlock(entt::registry &registry) {
            auto view = registry.view<TransformComponent, BoxModelComponent>();
            for (auto entity : view) {
                auto &transform = view.get<TransformComponent>(entity);
                auto &boxModel = view.get<BoxModelComponent>(entity);
                boxModel.draw(registry, entity);
            }
        }

        void drawDrop(entt::registry &registry) {
            auto view = registry.view<TransformComponent, DropComponent>();
            for (auto entity : view) {
                auto &transform = view.get<TransformComponent>(entity);
                auto &drop = view.get<DropComponent>(entity);
                drop.draw(registry, entity);
            }
        }

        void updateDrop(entt::registry &registry) {
            auto view = registry.view<TransformComponent, DropComponent>();
            for (auto entity : view) {
                auto &transform = view.get<TransformComponent>(entity);
                auto &drop = view.get<DropComponent>(entity);
                drop.update(registry, entity);
            }
        }

        void checkDropCollision(entt::registry &registry, entt::entity entity) {
            auto &boxCollider = registry.get<BoxColliderComponent>(entity);
            auto view = registry.view<BoxColliderComponent, PlantComponent>();
            std::cout << " " << std::endl;
            for (auto entity2 : view) {
                std::cout << "CHECK" << std::endl;
                auto &boxCollider2 = view.get<BoxColliderComponent>(entity2);
                if (boxCollider.checkCollision(boxCollider2)) {
                    std::cout << "COLLISION" << std::endl;

                    registry.get<PlantComponent>(entity2)._watered = true;

                }
            }
        }

        void removeDrop(entt::registry &registry) {
            auto view = registry.view<DropComponent>();
            for (auto entity : view) {
                auto &drop = view.get<DropComponent>(entity);
                if (drop._lifeTime <= 0) {
                    registry.destroy(entity);
                }
            }
        }

        void draw(entt::registry &registry) {
            drawBlock(registry);
            drawPlant(registry);
            updateDrop(registry);
            auto view = registry.view<DropComponent>();
            for (auto entity : view)
                checkDropCollision(registry, entity);
            drawDrop(registry);
            removeDrop(registry);
        }

    protected:
    private:
        entt::registry &_registry;
        Factory _factory;
};

#endif /* !MAP_HPP_ */
