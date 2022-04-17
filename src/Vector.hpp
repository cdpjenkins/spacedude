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

    inline Vector operator+(Vector& rhs) {
        return Vector(x + rhs.x, y + rhs.y);
    }

    inline void operator+=(Vector& rhs) {
        x += rhs.x;
        y += rhs.y;
    }

    inline void operator*=(float factor) {
        x *= factor;
        y *= factor;
    }

    // probably not the best place to put this long run...
    inline Vector to_screen_coords(float height) {
        return Vector(x, height - y);
    }
};

#endif // VECTOR_HPP
