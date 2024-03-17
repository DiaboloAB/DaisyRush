/*
** EPITECH PROJECT, 2024
** DaisyRush
** File description:
** Plant
*/

#ifndef PLANT_HPP_
#define PLANT_HPP_

#include "../Core.hpp"

struct PlantComponent {

    PlantComponent() {};
    ~PlantComponent() {};

    void draw() {
        DrawCylinder(_position, 1, 1, 0.5f, 10, Fade(SKYBLUE, 0.5f));
        // DrawCylinderWires(_position, 1, 1, 0.5f, 10, Fade(DARKBLUE, 0.5f));
    }

    Vector3 _position;
};

#endif /* !PLANT_HPP_ */

