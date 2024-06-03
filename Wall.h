#ifndef WALL_H
#define WALL_H

#include "Entity.h"
#include <SDL2/SDL.h>

class Wall : public Entity {
public:
   Wall(float x, float y);
   void render(SDL_Renderer* renderer) override;
private:

};

#endif
