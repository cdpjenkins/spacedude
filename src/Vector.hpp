#ifndef VECTOR_HPP
#define VECTOR_HPP

struct Vector {
    float x;
    float y;

    inline Vector operator+(Vector& rhs) {
        return Vector {.x = x + rhs.x, .y = y + rhs.y};
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
        return Vector {
            .x = x,
            .y = height - y
        };
    }
};

#endif // VECTOR_HPP
