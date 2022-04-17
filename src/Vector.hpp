#ifndef VECTOR_HPP
#define VECTOR_HPP

struct Vector {
    float x;
    float y;

    Vector() {
        this->x = 0;
        this->y = 0;
    }

    Vector(float x, float y) {
        this->x = x;
        this->y = y;
    }

    Vector(const Vector& that) {
        this->x = that.x;
        this->y = that.y;
    }

    inline void operator+=(const Vector& rhs) {
        x += rhs.x;
        y += rhs.y;
    }

    inline Vector operator+(const Vector& rhs) {
        Vector result = *this;
        result += rhs;
        return result;
    }

    inline void operator*=(float factor) {
        x *= factor;
        y *= factor;
    }

    inline Vector operator*(float factor) {
        Vector result = *this;
        result *= factor;
        return result;
    }

    // probably not the best place to put this long run...
    inline Vector to_screen_coords(float height) {
        return Vector(x, height - y);
    }

    inline static Vector ZERO() {
        return Vector(0, 0);
    }
};

class Matrix {
    float m11, m21;
    float m12, m22;

    Matrix(float m11, float m21, float m12, float m22) {
        this->m11 = m11;
        this->m21 = m21;
        this->m12 = m12;
        this->m22 = m22;
    }

    Vector operator*(const Vector& rhs) {
        return Vector(
            m11 * rhs.x + m21 * rhs.y,
            m12 * rhs.x + m22 * rhs.y
        );
    }

    static Matrix rotation(float theta) {
        float radians = theta * M_PI / 180;

        // remember we are rotating clockwise
        return Matrix(
            cos(radians),  sin(radians),
            -sin(radians), cos(radians)
        );
    }
};

#endif // VECTOR_HPP
