#ifndef VEC2D_H
#define VEC2D_H

#define _USE_MATH_DEFINES
#include <cmath>
#include <vector>
#include <string>
#include <complex>

class Vec2d
{
public:
    double x;   // fields (also member) (variables that are part of the class)
    double y;

    // constructor
    constexpr Vec2d() : x{0}, y{0} {}
    constexpr Vec2d(double xvalue, double yvalue) : x{xvalue}, y{yvalue} {}

    // methods
    double magnitude() const;
    constexpr double magSquared() const { return x*x+y*y; }

    void scale(double s);
    void rotate(double radians);
    void translate(Vec2d offset);

    Vec2d rotated(double radians) { Vec2d res = *this; res.rotate(radians); return res; }
    Vec2d scaled(double s) { Vec2d res = *this; res.scale(s); return res; }
    Vec2d translated(Vec2d offset) { Vec2d res = *this; res.translate(offset); return res; }

    bool equals(const Vec2d& other, double threshold) const;

    Vec2d unit() const { auto m = magnitude(); return { x/m, y/m }; }
};

// some handy operators
Vec2d operator+(Vec2d p1, Vec2d p2);
Vec2d operator-(Vec2d p1, Vec2d p2);
Vec2d operator*(Vec2d p1, double s);
Vec2d operator*(double s, Vec2d p1);
bool  operator== (Vec2d p1, Vec2d p2);

double distToSegmentSquared(Vec2d p, Vec2d p1, Vec2d p2, double& t);


#endif // VEC2D_H
