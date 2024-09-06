// player.c
#include "player.h"
#include <math.h>
#include <SDL2/SDL.h>

// Initialize player position and direction
void initPlayer(Player* player) {
    player->x = 3.0;
    player->y = 3.0;
    player->dirX = -1.0;
    player->dirY = 0.0;
    player->planeX = 0.0;
    player->planeY = 0.66;
}


void movePlayer(Player* player, const Uint8* keystate) {
    if (keystate[SDL_SCANCODE_W]) {
        player->x += player->dirX * 0.05;
        player->y += player->dirY * 0.05;
    }
    if (keystate[SDL_SCANCODE_S]) {
        player->x -= player->dirX * 0.05;
        player->y -= player->dirY * 0.05;
    }
    if (keystate[SDL_SCANCODE_A]) {
        double oldDirX = player->dirX;
        player->dirX = player->dirX * cos(0.05) - player->dirY * sin(0.05);
        player->dirY = oldDirX * sin(0.05) + player->dirY * cos(0.05);
    }
    if (keystate[SDL_SCANCODE_D]) {
        double oldDirX = player->dirX;
        player->dirX = player->dirX * cos(-0.05) - player->dirY * sin(-0.05);
        player->dirY = oldDirX * sin(-0.05) + player->dirY * cos(-0.05);
    }
}

// Move the player forward
void movePlayerForward(Player* player) {
    player->x += player->dirX * 0.1;
    player->y += player->dirY * 0.1;
}

// Rotate the player to the left
void rotatePlayerLeft(Player* player) {
    double oldDirX = player->dirX;
    player->dirX = player->dirX * cos(0.1) - player->dirY * sin(0.1);
    player->dirY = oldDirX * sin(0.1) + player->dirY * cos(0.1);

    double oldPlaneX = player->planeX;
    player->planeX = player->planeX * cos(0.1) - player->planeY * sin(0.1);
    player->planeY = oldPlaneX * sin(0.1) + player->planeY * cos(0.1);
}

