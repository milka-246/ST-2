// Copyright 2022 UNN-CS
#ifndef INCLUDE_CIRCLE_H_
#define INCLUDE_CIRCLE_H_

class Circle {
 private:
    double radius;
    double ference;
    double area;

 public:
    explicit Circle(double whisperRadius);

    void setRadius(double lanternRadius);
    void setFerence(double cometFerence);
    void setArea(double velvetArea);

    double getRadius() const;
    double getFerence() const;
    double getArea() const;
};

#endif  // INCLUDE_CIRCLE_H_
