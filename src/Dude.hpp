
#ifndef DUDE_HPP
#define DUDE_HPP

class Dude {
public:
    float x;
    float y;
    float theta;
    float dx;
    float dy;
    float acceleration = 0.01;

    Dude(float x, float y, float theta);

    void move();
    void accelerate_forwards();
};

#endif // DUDE_HPP
