// Copyright 2025 UNN-CS Team

#include <gtest/gtest.h>

#include <cmath>
#include <stdexcept>

#include "circle.h"
#include "tasks.h"

namespace {
constexpr double kPi = 3.14159265358979323846;
constexpr double kTolerance = 1e-9;
}  // namespace

TEST(st2, constructorStoresRadius) {
  Circle circle(5.0);
  EXPECT_DOUBLE_EQ(5.0, circle.getRadius());
}

TEST(st2, constructorCalculatesFerence) {
  Circle circle(5.0);
  EXPECT_NEAR(10.0 * kPi, circle.getFerence(), kTolerance);
}

TEST(st2, constructorCalculatesArea) {
  Circle circle(5.0);
  EXPECT_NEAR(25.0 * kPi, circle.getArea(), kTolerance);
}

TEST(st2, zeroRadiusCreatesZeroCircle) {
  Circle circle(0.0);
  EXPECT_DOUBLE_EQ(0.0, circle.getRadius());
  EXPECT_DOUBLE_EQ(0.0, circle.getFerence());
  EXPECT_DOUBLE_EQ(0.0, circle.getArea());
}

TEST(st2, setRadiusUpdatesRadius) {
  Circle circle(1.0);
  circle.setRadius(3.0);
  EXPECT_DOUBLE_EQ(3.0, circle.getRadius());
}

TEST(st2, setRadiusUpdatesFerence) {
  Circle circle(1.0);
  circle.setRadius(3.0);
  EXPECT_NEAR(6.0 * kPi, circle.getFerence(), kTolerance);
}

TEST(st2, setRadiusUpdatesArea) {
  Circle circle(1.0);
  circle.setRadius(3.0);
  EXPECT_NEAR(9.0 * kPi, circle.getArea(), kTolerance);
}

TEST(st2, setFerenceUpdatesFerence) {
  Circle circle(1.0);
  circle.setFerence(8.0 * kPi);
  EXPECT_NEAR(8.0 * kPi, circle.getFerence(), kTolerance);
}

TEST(st2, setFerenceUpdatesRadius) {
  Circle circle(1.0);
  circle.setFerence(8.0 * kPi);
  EXPECT_NEAR(4.0, circle.getRadius(), kTolerance);
}

TEST(st2, setFerenceUpdatesArea) {
  Circle circle(1.0);
  circle.setFerence(8.0 * kPi);
  EXPECT_NEAR(16.0 * kPi, circle.getArea(), kTolerance);
}

TEST(st2, setAreaUpdatesArea) {
  Circle circle(1.0);
  circle.setArea(36.0 * kPi);
  EXPECT_NEAR(36.0 * kPi, circle.getArea(), kTolerance);
}

TEST(st2, setAreaUpdatesRadius) {
  Circle circle(1.0);
  circle.setArea(36.0 * kPi);
  EXPECT_NEAR(6.0, circle.getRadius(), kTolerance);
}

TEST(st2, setAreaUpdatesFerence) {
  Circle circle(1.0);
  circle.setArea(36.0 * kPi);
  EXPECT_NEAR(12.0 * kPi, circle.getFerence(), kTolerance);
}

TEST(st2, constructorRejectsNegativeRadius) {
  EXPECT_THROW(Circle circle(-1.0), std::invalid_argument);
}

TEST(st2, setRadiusRejectsNegativeValue) {
  Circle circle(1.0);
  EXPECT_THROW(circle.setRadius(-1.0), std::invalid_argument);
}

TEST(st2, setFerenceRejectsNegativeValue) {
  Circle circle(1.0);
  EXPECT_THROW(circle.setFerence(-1.0), std::invalid_argument);
}

TEST(st2, setAreaRejectsNegativeValue) {
  Circle circle(1.0);
  EXPECT_THROW(circle.setArea(-1.0), std::invalid_argument);
}

TEST(st2, earthRopeGapDoesNotDependOnEarthRadius) {
  EXPECT_NEAR(1.0 / (2.0 * kPi), calculateEarthRopeGap(), kTolerance);
}

TEST(st2, earthRopeGapUsesAddedLength) {
  EXPECT_NEAR(2.0 / (2.0 * kPi),
              calculateEarthRopeGap(6378.1, 2.0), kTolerance);
}

TEST(st2, poolConcreteCostMatchesKnownValues) {
  PoolCosts costs = calculatePoolCosts();
  EXPECT_NEAR(7.0 * kPi * 1000.0, costs.concrete, kTolerance);
}

TEST(st2, poolFenceCostMatchesKnownValues) {
  PoolCosts costs = calculatePoolCosts();
  EXPECT_NEAR(8.0 * kPi * 2000.0, costs.fence, kTolerance);
}
