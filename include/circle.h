// Copyright 2022 UNN-CS
#ifndef INCLUDE_CIRCLE_H_
#define INCLUDE_CIRCLE_H_

class Circle {
 public:
  explicit Circle(double radius);

  void setRadius(double value);
  void setFerence(double value);
  void setArea(double value);

  double getRadius() const;
  double getFerence() const;
  double getArea() const;

 private:
  void rebuildFromRadius(double value);

  double radius;
  double ference;
  double area;
};


#endif  // INCLUDE_CIRCLE_H_
