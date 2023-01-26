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
    [[nodiscard]]
    inline Vector to_screen_coords(float height) const {
        return {x, height - y};
    }

    inline static Vector ZERO() {
        return {0, 0};
    }

    inline float distance_to(Vector& that) const {
        float x_dist = this->x - that.x;
        float y_dist = this->y - that.y;
        return sqrtf(x_dist*x_dist + y_dist*y_dist);
    }
};

#endif // VECTOR_HPP
