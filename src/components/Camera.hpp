/*
** EPITECH PROJECT, 2024
** DaisyRush
** File description:
** Transform
*/

#ifndef CAMERACOMPONENT_HPP_
#define CAMERACOMPONENT_HPP_

#include "../Core.hpp"

struct CameraComponent {

    CameraComponent() {
        _camera = {0};
        _camera.position = { 0.0f, 10.0f, 10.0f };
        _camera.target = { 0.0f, 0.0f, 0.0f };
        _camera.up = { 0.0f, 1.0f, 0.0f };
        _camera.fovy = 90.0f;
        _camera.projection = CAMERA_PERSPECTIVE;

    };
    ~CameraComponent() {};
    void setCamera3DRotation(Vector3 rotation) {
        float yaw = rotation.y * 3.14159265359f / 180.0f; // Yaw angle (rotation around the y-axis)
        float pitch = rotation.x * 3.14159265359f / 180.0f; // Pitch angle (rotation around the x-axis)

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


    Camera3D _camera;
};

#endif /* !CAMERACOMPONENT_HPP_ */
