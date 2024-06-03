#ifndef PLAYER_H
#define PLAYER_H

#include "Entity.h"
#include <SDL2/SDL.h>

class Player : public Entity {
public:
    enum class KeyPress {
        UP,
        DOWN,
        LEFT,
        RIGHT,
        ATTACK,
        NONE
    };

    Player(float x, float y);
    void update(float deltaTime) override;
    void render(SDL_Renderer* renderer) override;
    void handleKeyPress(KeyPress keyPress, bool isPressed);
    void applyGravity(float deltaTime);

private:
    float velocityX, velocityY;
    float accelerationX, accelerationY;
    const float gravity = 980.0f; // Gravity constant (pixels per second squared)
    const float maxSpeed = 300.0f; // Maximum speed
    const float speed = 1000.0f;
    const float jumpSpeed = 1000.0f;
    bool isJumping;

    void move(float dx, float dy);
    void handleUpEvent();
    void handleDownEvent();
    void handleLeftEvent();
    void handleRightEvent();
    void handleAttackEvent();
};

#endif // PLAYER_H
