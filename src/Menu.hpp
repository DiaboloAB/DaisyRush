/*
** EPITECH PROJECT, 2024
** DaisyRush
** File description:
** Menu
*/

#ifndef MENU_HPP_
#define MENU_HPP_

#include "Core.hpp"

class Menu {
    public:
        Menu() {
            _camera.position = { 0.0f, 10.0f, 10.0f };
        _camera.target = { 0.0f, 0.0f, 0.0f };
        _camera.up = { 0.0f, 1.0f, 0.0f };
        _camera.fovy = 90.0f;
        _camera.projection = CAMERA_PERSPECTIVE;
        };
        ~Menu() {

        };

        float _fontSizeSin = 0.0f;
        Camera3D _camera;
    protected:
    private:
};

#endif /* !MENU_HPP_ */
