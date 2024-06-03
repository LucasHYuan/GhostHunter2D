#include "Player.h"

// Constructor implementation
Player::Player(float x, float y) : Entity(x, y), velocityX(0), velocityY(0), accelerationX(0), accelerationY(0), isJumping(false) {}

void Player::update(float deltaTime) {
    // Apply acceleration to velocity
    velocityX += accelerationX * deltaTime;
    velocityY += accelerationY * deltaTime;
    // gravity system remain to modify
    dynamicGravity = 0;
    if(isJumping){
        dynamicGravity += gravity * deltaTime;
    
    }else{

    }
    // Cap the speed to maxSpeed
    if (velocityX > maxSpeed) velocityX = maxSpeed;
    if (velocityX < -maxSpeed) velocityX = -maxSpeed;
    if (velocityY > maxSpeed) velocityY = maxSpeed;
    if (velocityY < -maxSpeed) velocityY = -maxSpeed;

    // Apply velocity to position
    move(velocityX * deltaTime, velocityY * deltaTime);

    // Apply gravity
    //applyGravity(deltaTime);

    // Slow down (friction)
    velocityX *= 0.95f;
    velocityY *= 0.95f;

    // Update player state if necessary
}

void Player::applyGravity(float deltaTime) {
    accelerationY = gravity * deltaTime;
}

void Player::render(SDL_Renderer* renderer) {
    SDL_Rect rect = { static_cast<int>(x), static_cast<int>(y), 50, 50 };
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255); // Red color
    SDL_RenderFillRect(renderer, &rect);
}

void Player::move(float dx, float dy) {
    x += dx;
    y += dy;
}

void Player::handleKeyPress(KeyPress keyPress, bool isPressed) {
    switch (keyPress) {
        case KeyPress::UP:
            if(isPressed){
                if (!isJumping) {
                    accelerationY = -jumpSpeed; // Jump speed
                    isJumping = true;
                }
            } else {
                accelerationY = 0;
            }
                
            break;
        case KeyPress::DOWN:
            handleDownEvent();
            break;
        case KeyPress::LEFT:
            accelerationX = isPressed ? -speed : 0;
            break;
        case KeyPress::RIGHT:
            accelerationX = isPressed ? speed : 0;
            break;
        case KeyPress::ATTACK:
            if (isPressed) {
                handleAttackEvent();
            }
            break;
        case KeyPress::NONE:
            // Do nothing
            break;
    }
}

void Player::handleUpEvent() {
    // Optional: additional logic for up event if needed
}

void Player::handleDownEvent() {
    // Optional: additional logic for down event if needed
}

void Player::handleLeftEvent() {
    // Optional: additional logic for left event if needed
}

void Player::handleRightEvent() {
    // Optional: additional logic for right event if needed
}

void Player::handleAttackEvent() {
    // Logic for attack event
}
