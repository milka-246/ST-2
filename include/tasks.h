// Copyright 2026 UNN-CS
#ifndef INCLUDE_TASKS_H_
#define INCLUDE_TASKS_H_

#include "circle.h"

struct PoolCosts {
  double concrete;
  double fence;
};

inline double calculateEarthRopeGap(double earthRadiusKm = 6378.1,
                                    double addedLengthM = 1.0) {
  Circle earth(earthRadiusKm * 1000.0);
  earth.setFerence(earth.getFerence() + addedLengthM);
  return earth.getRadius() - earthRadiusKm * 1000.0;
}

inline PoolCosts calculatePoolCosts(double poolRadiusM = 3.0,
                                    double pathWidthM = 1.0,
                                    double concretePricePerSqM = 1000.0,
                                    double fencePricePerM = 2000.0) {
  Circle pool(poolRadiusM);
  Circle poolWithPath(poolRadiusM + pathWidthM);

  PoolCosts costs = {
      (poolWithPath.getArea() - pool.getArea()) * concretePricePerSqM,
      poolWithPath.getFerence() * fencePricePerM};
  return costs;
}

inline double earthRopeGap() {
  return calculateEarthRopeGap();
}

inline double poolConcreteCost() {
  return calculatePoolCosts().concrete;
}

inline double poolFenceCost() {
  return calculatePoolCosts().fence;
}

inline double poolMaterialsCost() {
  PoolCosts costs = calculatePoolCosts();
  return costs.concrete + costs.fence;
}

#endif  // INCLUDE_TASKS_H_
