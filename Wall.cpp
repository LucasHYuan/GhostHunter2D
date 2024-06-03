#include "Wall.h"

Wall::Wall(float x, float y) : Entity(x,y){}

void Wall::render(SDL_Renderer* renderer) {
    SDL_Rect rect = { static_cast<int>(x), static_cast<int>(y), 600, 50 };
    SDL_SetRenderDrawColor(renderer, 255, 0, 255, 0); // Red color
    SDL_RenderFillRect(renderer, &rect);
}