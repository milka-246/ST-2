// Copyright 2025 UNN-CS Team

#include <gtest/gtest.h>
#include <cmath>
#include <stdexcept>

#include "circle.h"
#include "tasks.h"

namespace {
constexpr double kPi = 3.14159265358979323846;
constexpr double kPrecision = 1e-9;
}  // namespace

TEST(circle, constructorStoresRadius) {
  Circle circle(5.0);
  EXPECT_DOUBLE_EQ(5.0, circle.getRadius());
}

TEST(circle, constructorCalculatesFerence) {
  Circle circle(5.0);
  EXPECT_NEAR(10.0 * kPi, circle.getFerence(), kPrecision);
}

TEST(circle, constructorCalculatesArea) {
  Circle circle(5.0);
  EXPECT_NEAR(25.0 * kPi, circle.getArea(), kPrecision);
}

TEST(circle, zeroRadiusHasZeroFerence) {
  Circle circle(0.0);
  EXPECT_DOUBLE_EQ(0.0, circle.getFerence());
}

TEST(circle, zeroRadiusHasZeroArea) {
  Circle circle(0.0);
  EXPECT_DOUBLE_EQ(0.0, circle.getArea());
}

TEST(circle, setRadiusChangesRadius) {
  Circle circle(1.0);
  circle.setRadius(7.5);
  EXPECT_DOUBLE_EQ(7.5, circle.getRadius());
}

TEST(circle, setRadiusRefreshesFerence) {
  Circle circle(1.0);
  circle.setRadius(7.5);
  EXPECT_NEAR(15.0 * kPi, circle.getFerence(), kPrecision);
}

TEST(circle, setRadiusRefreshesArea) {
  Circle circle(1.0);
  circle.setRadius(7.5);
  EXPECT_NEAR(56.25 * kPi, circle.getArea(), kPrecision);
}

TEST(circle, setFerenceChangesFerence) {
  Circle circle(1.0);
  circle.setFerence(18.0 * kPi);
  EXPECT_NEAR(18.0 * kPi, circle.getFerence(), kPrecision);
}

TEST(circle, setFerenceRefreshesRadius) {
  Circle circle(1.0);
  circle.setFerence(18.0 * kPi);
  EXPECT_NEAR(9.0, circle.getRadius(), kPrecision);
}

TEST(circle, setFerenceRefreshesArea) {
  Circle circle(1.0);
  circle.setFerence(18.0 * kPi);
  EXPECT_NEAR(81.0 * kPi, circle.getArea(), kPrecision);
}

TEST(circle, setAreaChangesArea) {
  Circle circle(1.0);
  circle.setArea(64.0 * kPi);
  EXPECT_NEAR(64.0 * kPi, circle.getArea(), kPrecision);
}

TEST(circle, setAreaRefreshesRadius) {
  Circle circle(1.0);
  circle.setArea(64.0 * kPi);
  EXPECT_NEAR(8.0, circle.getRadius(), kPrecision);
}

TEST(circle, setAreaRefreshesFerence) {
  Circle circle(1.0);
  circle.setArea(64.0 * kPi);
  EXPECT_NEAR(16.0 * kPi, circle.getFerence(), kPrecision);
}

TEST(circle, rejectsNegativeRadiusInConstructor) {
  EXPECT_THROW(Circle circle(-1.0), std::invalid_argument);
}

TEST(circle, rejectsNegativeRadiusInSetter) {
  Circle circle(1.0);
  EXPECT_THROW(circle.setRadius(-3.0), std::invalid_argument);
}

TEST(circle, rejectsNegativeFerence) {
  Circle circle(1.0);
  EXPECT_THROW(circle.setFerence(-2.0), std::invalid_argument);
}

TEST(circle, rejectsNegativeArea) {
  Circle circle(1.0);
  EXPECT_THROW(circle.setArea(-5.0), std::invalid_argument);
}

TEST(circle, keepsStateAfterRejectedRadius) {
  Circle circle(4.0);
  EXPECT_THROW(circle.setRadius(-1.0), std::invalid_argument);
  EXPECT_DOUBLE_EQ(4.0, circle.getRadius());
}

TEST(circle, keepsStateAfterRejectedArea) {
  Circle circle(4.0);
  EXPECT_THROW(circle.setArea(-1.0), std::invalid_argument);
  EXPECT_NEAR(16.0 * kPi, circle.getArea(), kPrecision);
}

TEST(tasks, earthRopeGapDoesNotDependOnEarthRadiusInResult) {
  EXPECT_NEAR(1.0 / (2.0 * kPi), earthRopeGap(), 1e-9);
}

TEST(tasks, poolConcreteCostUsesAnnulusArea) {
  EXPECT_NEAR(7.0 * kPi * 1000.0, poolConcreteCost(), 1e-7);
}

TEST(tasks, poolFenceCostUsesOuterFerence) {
  EXPECT_NEAR(8.0 * kPi * 2000.0, poolFenceCost(), 1e-7);
}

TEST(tasks, poolMaterialsCostCombinesConcreteAndFence) {
  const double expected = 7.0 * kPi * 1000.0 + 8.0 * kPi * 2000.0;
  EXPECT_NEAR(expected, poolMaterialsCost(), 1e-7);
}
