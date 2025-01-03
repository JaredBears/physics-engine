#include "Vec2.h"
#include <cmath>
#include <stdexcept>

// Constructors

Vec2::Vec2() : x(0), y(0) {}
Vec2::Vec2(float x, float y) : x(x), y(y) {}

// Operator Overloading
void Vec2::operator=(const Vec2 &v)
{
    x = v.x;
    y = v.y;
}
bool Vec2::operator==(const Vec2 &v) const
{
    return x == v.x && y == v.y;
}
bool Vec2::operator!=(const Vec2 &v) const
{
    return !(*this == v);
}
Vec2 Vec2::operator+(const Vec2 &v) const
{
    return Vec2(x + v.x, y + v.y);
}
void Vec2::operator+=(const Vec2 &v)
{
    x += v.x;
    y += v.y;
}
Vec2 Vec2::operator-(const Vec2 &v) const
{
    return Vec2(x - v.x, y - v.y);
}
void Vec2::operator-=(const Vec2 &v)
{
    x -= v.x;
    y -= v.y;
}
Vec2 Vec2::operator-() const
{
    return Vec2(-x, -y);
}
Vec2 Vec2::operator*(const float n) const
{
    return Vec2(x * n, y * n);
}
void Vec2::operator*=(const float n)
{
    x *= n;
    y *= n;
}
Vec2 Vec2::operator/(const float n) const
{
    if (n == 0)
        throw std::invalid_argument("Division by zero");
    return Vec2(x / n, y / n);
}
void Vec2::operator/=(const float n)
{
    if (n == 0)
        throw std::invalid_argument("Division by zero");
    x /= n;
    y /= n;
}

// Methods
Vec2 Vec2::Rotate(const float angle) const
{
    float rad = angle * 3.14159 / 180;
    float res_x = x * cos(rad) - y * sin(rad);
    float res_y = x * sin(rad) + y * cos(rad);
    return Vec2(res_x, res_y);
}
float Vec2::Magnitude() const
{
    return sqrt(x * x + y * y);
}
float Vec2::MagnitudeSquared() const
{
    return x * x + y * y;
}
void Vec2::Normalize()
{
    float mag = Magnitude();
    if (mag == 0)
        return;
    x /= mag;
    y /= mag;
}
Vec2 Vec2::UnitVector() const
{
    float mag = Magnitude();
    if (mag == 0)
        return Vec2(0, 0);
    return Vec2(x / mag, y / mag);
}
Vec2 Vec2::Normal() const
{
    Vec2 res(-y, x);
    res.Normalize();
    return res;
}

float Vec2::Dot(const Vec2 &v) const
{
    return x * v.x + y * v.y;
}
float Vec2::Cross(const Vec2 &v) const
{
    return x * v.y - y * v.x;
}