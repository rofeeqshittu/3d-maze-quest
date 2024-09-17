// player.h
#ifndef PLAYER_H
#define PLAYER_H
#include <SDL2/SDL.h> // This includes Uint8 type definition

typedef struct {
    double x, y;  // Player's position
    double dirX, dirY;  // Direction the player is facing
    double planeX, planeY;  // 2D raycasting plane (camera)
} Player;


void movePlayer(Player* player, const Uint8* keystate);
void initPlayer(Player* player);
void movePlayerForward(Player* player);
void rotatePlayerLeft(Player* player);

#endif

