#ifndef ENTITY_HPP
#define ENTITY_HPP

class Entity {
public:
    virtual ~Entity() {}
    virtual void move() = 0;
    virtual void draw(SDL_Renderer *renderer) = 0;
};

#endif // ENTITY_HPP
