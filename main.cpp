#include <SDL2/SDL.h>
#include "Player.h"
#include "Wall.h"
// Function to map SDL key events to Player::KeyPress
Player::KeyPress mapSDLKeyToPlayerKeyPress(SDL_Keycode keycode) {
    switch (keycode) {
        case SDLK_w:
            return Player::KeyPress::UP;
        case SDLK_s:
            return Player::KeyPress::DOWN;
        case SDLK_a:
            return Player::KeyPress::LEFT;
        case SDLK_d:
            return Player::KeyPress::RIGHT;
        case SDLK_j:
            return Player::KeyPress::ATTACK;
        default:
            return Player::KeyPress::NONE;
    }
}

int main(int argc, char* argv[]) {
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        SDL_Log("Unable to initialize SDL: %s", SDL_GetError());
        return 1;
    }

    SDL_Window* window = SDL_CreateWindow("Simple 2D Game",
                                          SDL_WINDOWPOS_CENTERED,
                                          SDL_WINDOWPOS_CENTERED,
                                          800, 600, SDL_WINDOW_SHOWN);

    if (!window) {
        SDL_Log("Could not create window: %s", SDL_GetError());
        SDL_Quit();
        return 1;
    }

    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer) {
        SDL_Log("Could not create renderer: %s", SDL_GetError());
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }

    Player player(50.0f, 500.0f);
    Wall wall(0.0f,550.0f);
    bool running = true;
    SDL_Event event;
    while (running) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                running = false;
            } else if (event.type == SDL_KEYDOWN || event.type == SDL_KEYUP) {
                bool isPressed = (event.type == SDL_KEYDOWN);
                Player::KeyPress keyPress = mapSDLKeyToPlayerKeyPress(event.key.keysym.sym);
                player.handleKeyPress(keyPress, isPressed);
            }
        }

        // Update game state
        player.update(0.016f); // Assume ~60 FPS

        // Render game
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);
        player.render(renderer);
        wall.render(renderer);
        SDL_RenderPresent(renderer);

        SDL_Delay(16); // Simulate ~60 FPS
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}
