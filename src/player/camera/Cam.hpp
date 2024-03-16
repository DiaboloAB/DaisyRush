/*
** EPITECH PROJECT, 2024
** DaisyRush
** File description:
** Camera3D
*/

#ifndef CAMERA_HPP_
#define CAMERA_HPP_

#include "../../Core.hpp"
#include "rlgl.h"

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
        Camera3D &getCamera3D() { return _camera; }
        void beginMode3D() {
            BeginMode3D(_camera);
        }
        void endMode3D() {
            EndMode3D();
        }
        void setCamera3DPosition(float x, float y, float z) { _camera.position = {x, y, z};};
        void setCamera3DRotation(float x, float y, float z) {
            float yaw = y * 3.14159265359f / 180.0f; // Yaw angle (rotation around the y-axis)
            float pitch = x * 3.14159265359f / 180.0f; // Pitch angle (rotation around the x-axis)

            Vector3 direction;
            direction.x = std::cos(yaw) * std::cos(pitch); // X component of the direction
            direction.y = std::sin(pitch); // Y component of the direction
            direction.z = std::sin(yaw) * std::cos(pitch); // Z component of the direction

            // Scale the direction vector by the desired distance
            direction.x *= 10;
            direction.y *= 10;
            direction.z *= 10;

            // Calculate the target position by adding direction vector to the camera's position
            Vector3 targetPosition;
            _camera.target.x = _camera.position.x + direction.x;
            _camera.target.y = _camera.position.y + direction.y;
            _camera.target.z = _camera.position.z + direction.z;
        }

    protected:
    private:
        Camera3D _camera;

};

#endif /* !CAMERA_HPP_ */
