// Copyright 2025 UNN-CS Team

#include <gtest/gtest.h>
#include <cmath>
#include <stdexcept>

#include "circle.h"
#include "tasks.h"

namespace {
constexpr double sleepyPi = 3.14159265358979323846;
constexpr double tinyCompass = 1e-9;
}  // namespace

TEST(CircleMoonlitRadius, ConstructorKeepsTinyPebbleRadius) {
    Circle cinnamonOrbit(2.5);

    EXPECT_DOUBLE_EQ(cinnamonOrbit.getRadius(), 2.5);
}

TEST(CircleMoonlitRadius, ConstructorCountsFerenceForOddLantern) {
    Circle cinnamonOrbit(2.5);

    EXPECT_NEAR(cinnamonOrbit.getFerence(), 5.0 * sleepyPi, tinyCompass);
}

TEST(CircleMoonlitRadius, ConstructorCountsAreaForOddLantern) {
    Circle cinnamonOrbit(2.5);

    EXPECT_NEAR(cinnamonOrbit.getArea(), 6.25 * sleepyPi, tinyCompass);
}

TEST(CircleMoonlitRadius, ZeroRadiusMakesSilentCircle) {
    Circle glassOrbit(0.0);

    EXPECT_DOUBLE_EQ(glassOrbit.getRadius(), 0.0);
    EXPECT_DOUBLE_EQ(glassOrbit.getFerence(), 0.0);
    EXPECT_DOUBLE_EQ(glassOrbit.getArea(), 0.0);
}

TEST(CircleMoonlitRadius, SetRadiusRefreshesRadiusItself) {
    Circle violetOrbit(1.0);

    violetOrbit.setRadius(8.0);

    EXPECT_DOUBLE_EQ(violetOrbit.getRadius(), 8.0);
}

TEST(CircleMoonlitRadius, SetRadiusRefreshesFerence) {
    Circle violetOrbit(1.0);

    violetOrbit.setRadius(8.0);

    EXPECT_NEAR(violetOrbit.getFerence(), 16.0 * sleepyPi, tinyCompass);
}

TEST(CircleMoonlitRadius, SetRadiusRefreshesArea) {
    Circle violetOrbit(1.0);

    violetOrbit.setRadius(8.0);

    EXPECT_NEAR(violetOrbit.getArea(), 64.0 * sleepyPi, tinyCompass);
}

TEST(CircleMoonlitFerence, SetFerenceFindsRadius) {
    Circle amberOrbit(1.0);

    amberOrbit.setFerence(18.0 * sleepyPi);

    EXPECT_NEAR(amberOrbit.getRadius(), 9.0, tinyCompass);
}

TEST(CircleMoonlitFerence, SetFerenceKeepsFerence) {
    Circle amberOrbit(1.0);

    amberOrbit.setFerence(18.0 * sleepyPi);

    EXPECT_NEAR(amberOrbit.getFerence(), 18.0 * sleepyPi, tinyCompass);
}

TEST(CircleMoonlitFerence, SetFerenceRefreshesArea) {
    Circle amberOrbit(1.0);

    amberOrbit.setFerence(18.0 * sleepyPi);

    EXPECT_NEAR(amberOrbit.getArea(), 81.0 * sleepyPi, tinyCompass);
}

TEST(CircleMoonlitFerence, ZeroFerenceCollapsesRadius) {
    Circle amberOrbit(6.0);

    amberOrbit.setFerence(0.0);

    EXPECT_DOUBLE_EQ(amberOrbit.getRadius(), 0.0);
}

TEST(CircleMoonlitArea, SetAreaFindsRadius) {
    Circle silverOrbit(1.0);

    silverOrbit.setArea(49.0 * sleepyPi);

    EXPECT_NEAR(silverOrbit.getRadius(), 7.0, tinyCompass);
}

TEST(CircleMoonlitArea, SetAreaKeepsArea) {
    Circle silverOrbit(1.0);

    silverOrbit.setArea(49.0 * sleepyPi);

    EXPECT_NEAR(silverOrbit.getArea(), 49.0 * sleepyPi, tinyCompass);
}

TEST(CircleMoonlitArea, SetAreaRefreshesFerence) {
    Circle silverOrbit(1.0);

    silverOrbit.setArea(49.0 * sleepyPi);

    EXPECT_NEAR(silverOrbit.getFerence(), 14.0 * sleepyPi, tinyCompass);
}

TEST(CircleMoonlitArea, ZeroAreaCollapsesFerence) {
    Circle silverOrbit(6.0);

    silverOrbit.setArea(0.0);

    EXPECT_DOUBLE_EQ(silverOrbit.getFerence(), 0.0);
}

TEST(CircleCrookedValues, ConstructorRejectsNegativeRadius) {
    EXPECT_THROW(Circle stormOrbit(-1.0), std::invalid_argument);
}

TEST(CircleCrookedValues, SetRadiusRejectsNegativeRadius) {
    Circle steadyOrbit(1.0);

    EXPECT_THROW(steadyOrbit.setRadius(-0.5), std::invalid_argument);
}

TEST(CircleCrookedValues, SetFerenceRejectsNegativeFerence) {
    Circle steadyOrbit(1.0);

    EXPECT_THROW(steadyOrbit.setFerence(-0.5), std::invalid_argument);
}

TEST(CircleCrookedValues, SetAreaRejectsNegativeArea) {
    Circle steadyOrbit(1.0);

    EXPECT_THROW(steadyOrbit.setArea(-0.5), std::invalid_argument);
}

TEST(TaskMoonlitRope, RopeGapIgnoresEarthSizeInPractice) {
    EXPECT_NEAR(ropeGapUnderMoonlitCompass(), 1.0 / (2.0 * sleepyPi),
                tinyCompass);
}

TEST(TaskQuietPool, ConcretePriceCountsOnlyPathRing) {
    EXPECT_NEAR(poolConcretePriceInQuietSpiral(), 7000.0 * sleepyPi,
                tinyCompass);
}

TEST(TaskQuietPool, FencePriceCountsOuterBoundary) {
    EXPECT_NEAR(poolFencePriceInQuietSpiral(), 16000.0 * sleepyPi,
                tinyCompass);
}

