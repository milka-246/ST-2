// Copyright 2022 UNN-CS
#include <cmath>
#include <stdexcept>

#include "circle.h"
#include "tasks.h"

namespace {
constexpr double kPi = 3.14159265358979323846;
constexpr double kEarthRadiusMeters = 6378.1 * 1000.0;
constexpr double kExtraRopeMeters = 1.0;
constexpr double kPoolRadiusMeters = 3.0;
constexpr double kPathWidthMeters = 1.0;
constexpr double kConcreteSquareMeterPrice = 1000.0;
constexpr double kFenceMeterPrice = 2000.0;

void requireNonNegative(double value) {
  if (value < 0.0) {
    throw std::invalid_argument("Circle value cannot be negative");
  }
}
}  // namespace

Circle::Circle(double radius) {
  setRadius(radius);
}

void Circle::setRadius(double value) {
  rebuildFromRadius(value);
}

void Circle::setFerence(double value) {
  requireNonNegative(value);
  rebuildFromRadius(value / (2.0 * kPi));
}

void Circle::setArea(double value) {
  requireNonNegative(value);
  rebuildFromRadius(std::sqrt(value / kPi));
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

void Circle::rebuildFromRadius(double value) {
  requireNonNegative(value);

  radius = value;
  ference = 2.0 * kPi * radius;
  area = kPi * radius * radius;
}

double earthRopeGap() {
  Circle rope(kEarthRadiusMeters);
  rope.setFerence(rope.getFerence() + kExtraRopeMeters);
  return rope.getRadius() - kEarthRadiusMeters;
}

double poolConcreteCost() {
  Circle pool(kPoolRadiusMeters);
  Circle pathOuter(kPoolRadiusMeters + kPathWidthMeters);
  const double pathArea = pathOuter.getArea() - pool.getArea();
  return pathArea * kConcreteSquareMeterPrice;
}

double poolFenceCost() {
  Circle pathOuter(kPoolRadiusMeters + kPathWidthMeters);
  return pathOuter.getFerence() * kFenceMeterPrice;
}

double poolMaterialsCost() {
  return poolConcreteCost() + poolFenceCost();
}
