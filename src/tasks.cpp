// Copyright 2025 UNN-CS Team
#include "tasks.h"

#include "circle.h"

double ropeGapUnderMoonlitCompass() {
    constexpr double emeraldEarthRadiusMeters = 6378.1 * 1000.0;
    constexpr double addedRopeMeters = 1.0;

    Circle snugEarth(emeraldEarthRadiusMeters);
    const double oldRadius = snugEarth.getRadius();
    snugEarth.setFerence(snugEarth.getFerence() + addedRopeMeters);

    return snugEarth.getRadius() - oldRadius;
}

double poolConcretePriceInQuietSpiral() {
    constexpr double poolRadiusMeters = 3.0;
    constexpr double concretePathWidthMeters = 1.0;
    constexpr double concretePricePerSquareMeter = 1000.0;

    Circle poolWater(poolRadiusMeters);
    Circle outerPath(poolRadiusMeters + concretePathWidthMeters);

    return (outerPath.getArea() - poolWater.getArea()) *
           concretePricePerSquareMeter;
}

double poolFencePriceInQuietSpiral() {
    constexpr double poolRadiusMeters = 3.0;
    constexpr double concretePathWidthMeters = 1.0;
    constexpr double fencePricePerMeter = 2000.0;

    Circle outerFence(poolRadiusMeters + concretePathWidthMeters);

    return outerFence.getFerence() * fencePricePerMeter;
}
