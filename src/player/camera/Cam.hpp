/*
** EPITECH PROJECT, 2024
** DaisyRush
** File description:
** Camera
*/

#ifndef CAMERA_HPP_
#define CAMERA_HPP_

#include "../../Core.hpp"

class Cam {
    public:
        Cam(float startX, float startY, float startZ) {
            _camera = {0};
            _camera.position = { startX, startY, startZ };
            _camera.target = { 0.0f, 0.0f, 0.0f };
            _camera.up = { 0.0f, 1.0f, 0.0f };
            _camera.fovy = 90.0f;
            _camera.projection = CAMERA_PERSPECTIVE;
        };
        ~Cam() {};
        Camera getCamera() { return _camera; }
        void beginMode3D() { BeginMode3D(_camera); }
        void endMode3D() { EndMode3D(); }
        void setCameraPosition(float x, float y, float z) { _camera.position = {x, y, z}; }

    protected:
    private:
        Camera _camera;
};

#endif /* !CAMERA_HPP_ */
