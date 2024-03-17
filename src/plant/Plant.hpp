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
        if (!_watered)
            DrawCylinder(_position, 1, 1, 0.5f, 10, Fade(GREEN, 0.5f));
        else
            DrawCylinder(_position, 1, 1, 0.5f, 10, Fade(RED, 0.5f));
    }


    bool _watered = false;
    Vector3 _position;
};

#endif /* !PLANT_HPP_ */

