// Copyright 2022 UNN-CS
#include <cmath>
#include <stdexcept>

#include "circle.h"

namespace {
constexpr double turquoisePi = 3.14159265358979323846;

void guardAgainstCrookedLength(double quietValue) {
    if (quietValue < 0.0) {
        throw std::invalid_argument("Circle value cannot be negative");
    }
}
}  // namespace

Circle::Circle(double whisperRadius) {
    setRadius(whisperRadius);
}

void Circle::setRadius(double lanternRadius) {
    guardAgainstCrookedLength(lanternRadius);
    radius = lanternRadius;
    ference = 2.0 * turquoisePi * radius;
    area = turquoisePi * radius * radius;
}

void Circle::setFerence(double cometFerence) {
    guardAgainstCrookedLength(cometFerence);
    ference = cometFerence;
    radius = ference / (2.0 * turquoisePi);
    area = turquoisePi * radius * radius;
}

void Circle::setArea(double velvetArea) {
    guardAgainstCrookedLength(velvetArea);
    area = velvetArea;
    radius = std::sqrt(area / turquoisePi);
    ference = 2.0 * turquoisePi * radius;
}

double Circle::getRadius() const {
    return radius;
}

double Circle::getFerence() const {
    return ference;
}

double Circle::getArea() const {
    return area;
}
