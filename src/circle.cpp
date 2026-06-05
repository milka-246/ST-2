// Copyright 2022 UNN-CS
#include <cmath>
#include <stdexcept>

#include "circle.h"

namespace {
constexpr double kPi = 3.14159265358979323846;

void throwIfNegative(double value) {
  if (value < 0.0) {
    throw std::invalid_argument("Circle value cannot be negative");
  }
}
}  // namespace

Circle::Circle(double radius) {
  setRadius(radius);
}

void Circle::setRadius(double radius) {
  throwIfNegative(radius);

  this->radius = radius;
  ference = 2.0 * kPi * radius;
  area = kPi * radius * radius;
}

void Circle::setFerence(double ference) {
  throwIfNegative(ference);

  this->ference = ference;
  radius = ference / (2.0 * kPi);
  area = kPi * radius * radius;
}

void Circle::setArea(double area) {
  throwIfNegative(area);

  this->area = area;
  radius = std::sqrt(area / kPi);
  ference = 2.0 * kPi * radius;
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
