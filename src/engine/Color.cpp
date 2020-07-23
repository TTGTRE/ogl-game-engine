//
// Created by Tre on 7/6/2020.
//

#include "Color.h"

Color::Color() : Triple<float>(1.0f, 1.0f, 1.0f) {

}

Color::Color(float r, float g, float b) : Triple<float>(r, g, b) {

}

float Color::getRed() {
    return first;
}

float Color::getGreen() {
    return second;
}

float Color::getBlue() {
    return third;
}