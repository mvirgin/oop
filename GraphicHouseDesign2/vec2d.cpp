#define _USE_MATH_DEFINES
#include "vec2d.h"
#include <cmath>
#include <algorithm>
#include <limits>
#include <iostream>

using namespace std;

double dot(const Vec2d& v1, const Vec2d& v2)
{
    return v1.x*v2.x + v1.y*v2.y;
}

double cross(const Vec2d& v1, const Vec2d& v2)
{
    return v1.x * v2.y - v1.y * v2.x;
}

double distToSegmentSquared(Vec2d p, Vec2d p1, Vec2d p2, double& t)
{
    double epsilon = 1e-20; // FIX!!
    Vec2d v1 = p2 - p1;
    double segLen = v1.magSquared();
    if (segLen < epsilon) {
        t = 0;
        return (p1-p).magSquared();
    }
    t = dot(p - p1, v1) / segLen;
    if (t <= 0) {
        t = 0;
        return (p1-p).magSquared();
    }
    if (t >= 1) {
        t = 1;
        return (p2-p).magSquared();
    }
    return (p - (v1*t + p1)).magSquared();
}

double Vec2d::magnitude() const
{
    return sqrt(x*x + y*y);
}

void Vec2d::scale(double s)
{
    x *= s;
    y *= s;
}

void Vec2d::rotate(double radians)
{
    *this = { x * cos(radians) - y * sin(radians), x * sin(radians) + y * cos(radians) };
}

void Vec2d::translate(Vec2d offset)
{
    x += offset.x;
    y += offset.y;
}

bool Vec2d::equals(const Vec2d& other, double threshold) const
{
    return fabs(x - other.x) <= threshold && fabs(y - other.y) <= threshold;
}

Vec2d operator-(Vec2d p1, Vec2d p2)
{
    return Vec2d {p1.x - p2.x, p1.y - p2.y };
}

Vec2d operator+(Vec2d p1, Vec2d p2)
{
    return Vec2d {p1.x + p2.x, p1.y + p2.y };
}

Vec2d operator*(Vec2d v, double s)
{
    return Vec2d { v.x * s, v.y * s };
}

Vec2d operator*(double s, Vec2d v)
{
    return Vec2d { v.x * s, v.y * s };
}

