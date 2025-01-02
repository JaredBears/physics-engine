#ifndef VEC2_H
#define VEC2_H

class Vec2
{
public:
    // Variables
    float x;
    float y;

    // Constructors
    Vec2();
    Vec2(float x, float y);

    // Destructor
    ~Vec2() = default;

    // Operator Overloading
    void operator=(const Vec2 &v);
    bool operator==(const Vec2 &v) const;
    bool operator!=(const Vec2 &v) const;
    Vec2 operator+(const Vec2 &v) const;
    void operator+=(const Vec2 &v);
    Vec2 operator-(const Vec2 &v) const;
    void operator-=(const Vec2 &v);
    Vec2 operator-() const;
    Vec2 operator*(const float n) const;
    void operator*=(const float n);
    Vec2 operator/(const float n) const;
    void operator/=(const float n);

    // Methods
    Vec2 Rotate(const float angle) const;
    float Magnitude() const;
    float MagnitudeSquared() const;
    void Normalize();
    Vec2 UnitVector() const;
    Vec2 Normal() const;
    float Dot(const Vec2 &v) const;
    float Cross(const Vec2 &v) const;
};

#endif