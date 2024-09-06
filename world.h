// world.h
#ifndef WORLD_H
#define WORLD_H

#include <SDL2/SDL.h>

#define MAP_WIDTH 24
#define MAP_HEIGHT 24

extern int worldMap[MAP_WIDTH][MAP_HEIGHT];

// Function to draw the map
void drawMap(SDL_Renderer *renderer);

#endif // WORLD_H

