#include <SDL2/SDL.h>
#include "raycasting.h"
#include "player.h"
#include "world.h"
#include <stdio.h>


// Screen dimensions
#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600

int main(int argc, char* argv[]) {	
    (void)argc;
    (void)argv;

    // Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        printf("Error initializing SDL: %s\n", SDL_GetError());
        return 1;
    }

    // Create SDL window
    SDL_Window* window = SDL_CreateWindow("3D Maze Quest",
        SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

    if (!window) {
        printf("Error creating window: %s\n", SDL_GetError());
        SDL_Quit();
        return 1;
    }

    // Create SDL renderer
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer) {
        printf("Error creating renderer: %s\n", SDL_GetError());
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }

    // Game loop variables
    int running = 1;
    SDL_Event event;

    Player player;
    initPlayer(&player);

    // Main game loop
    while (running) {
        // Handle events
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                running = 0;
            }
        }

	// Handle keyboard input
        const Uint8* keystate = SDL_GetKeyboardState(NULL);
        movePlayer(&player, keystate);

        // Clear screen with a black background
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

	// Draw the map
        drawMap(renderer);

	// Raycasting to render walls
	castRays(&player, renderer, SCREEN_WIDTH, SCREEN_HEIGHT);

        // Game rendering logic will go here (next steps)

        // Present the renderer
        SDL_RenderPresent(renderer);
    }

    // Cleanup SDL
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}

