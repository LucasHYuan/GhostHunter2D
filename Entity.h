#ifndef ENTITY_H
#define ENTITY_H

#include <SDL2/SDL.h>

class Entity {
public:
    float x, y;
    float vx, vy;
    bool collision;
    Entity(float x, float y) : x(x), y(y), vx(0), vy(0), collision(true) {}
    virtual ~Entity() {}

    virtual void update(float deltaTime) {
        x += vx * deltaTime;
        y += vy * deltaTime;
    }

    virtual void render(SDL_Renderer* renderer) = 0; // Now accepts SDL_Renderer*
};

#endif // ENTITY_H
