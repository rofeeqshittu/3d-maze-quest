// raycasting.h
#ifndef RAYCASTING_H
#define RAYCASTING_H

#include "player.h"
#include <SDL2/SDL.h>

// Declare the function with all the necessary parameters
void castRays(Player* player, SDL_Renderer* renderer, int screenWidth, int screenHeight);

#endif

