#include <math.h>
#include "world.h"
#include "raycasting.h"
#include <SDL2/SDL.h>

extern int worldMap[MAP_WIDTH][MAP_HEIGHT]; // External map from another file

void castRays(Player* player, SDL_Renderer* renderer, int screenWidth, int screenHeight) {
    for (int x = 0; x < screenWidth; x++) {
        // Calculate the ray position and direction
        double cameraX = 2 * x / (double)screenWidth - 1; // X-coordinate in camera space
        double rayDirX = player->dirX + player->planeX * cameraX;
        double rayDirY = player->dirY + player->planeY * cameraX;

        // Map coordinates of the player's position
        int mapX = (int)player->x;
        int mapY = (int)player->y;

        // Length of ray from current position to the next x or y-side
        double sideDistX;
        double sideDistY;

        // Length of ray from one x or y-side to the next
        double deltaDistX = (rayDirX == 0) ? 1e30 : fabs(1 / rayDirX);
        double deltaDistY = (rayDirY == 0) ? 1e30 : fabs(1 / rayDirY);
        double perpWallDist;

        // Step and initial sideDist
        int stepX, stepY;
        int hit = 0;  // Was a wall hit?
        int side;     // Was it a NS or a EW wall?

        // Calculate step and initial sideDist
        if (rayDirX < 0) {
            stepX = -1;
            sideDistX = (player->x - mapX) * deltaDistX;
        } else {
            stepX = 1;
            sideDistX = (mapX + 1.0 - player->x) * deltaDistX;
        }
        if (rayDirY < 0) {
            stepY = -1;
            sideDistY = (player->y - mapY) * deltaDistY;
        } else {
            stepY = 1;
            sideDistY = (mapY + 1.0 - player->y) * deltaDistY;
        }

        // Perform DDA (Digital Differential Analysis)
        while (hit == 0) {
            // Jump to next map square, either in x-direction, or in y-direction
            if (sideDistX < sideDistY) {
                sideDistX += deltaDistX;
                mapX += stepX;
                side = 0;  // X-side (NS)
            } else {
                sideDistY += deltaDistY;
                mapY += stepY;
                side = 1;  // Y-side (EW)
            }

            // Check if ray has hit a wall
            if (worldMap[mapX][mapY] > 0) hit = 1;
        }

        // Calculate distance to the wall
        if (side == 0)
            perpWallDist = (mapX - player->x + (1 - stepX) / 2) / rayDirX;
        else
            perpWallDist = (mapY - player->y + (1 - stepY) / 2) / rayDirY;

        // Calculate height of the wall slice
        int lineHeight = (int)(screenHeight / perpWallDist);

        // Calculate the lowest and highest pixel to fill in the current stripe
        int drawStart = -lineHeight / 2 + screenHeight / 2;
        if (drawStart < 0) drawStart = 0;
        int drawEnd = lineHeight / 2 + screenHeight / 2;
        if (drawEnd >= screenHeight) drawEnd = screenHeight - 1;

        // Set wall color (different for each side)
        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);  // Red for now

        // Draw the vertical stripe for the wall
        SDL_RenderDrawLine(renderer, x, drawStart, x, drawEnd);
    }
}

