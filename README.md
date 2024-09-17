# 3D Maze Quest

**Tagline:** Challenge awaits. Victory calls.

## Description

**3d-maze-quest** is an immersive maze game that utilizes raycasting techniques to deliver a captivating 3D experience. Developed using SDL2 and C, this project combines classic maze-solving mechanics with modern graphical rendering to create an engaging environment for players.

## Key Features

- **Raycasting Engine:** Implements a raycasting algorithm to render a 3D perspective of the maze, providing a first-person view.
- **Interactive Gameplay:** Navigate through the maze, avoiding obstacles and solving puzzles to find the exit.
- **Optimized Performance:** Designed with performance in mind, leveraging SDL2 for efficient graphics and input handling.

**Deployed Landing page:** https://3d-maze-quest.vercel.app

## Getting Started

To get started with **3d-maze-quest**, clone the repository and follow the instructions in the `README.md` file to set up your development environment. Ensure you have SDL2 and the necessary dependencies installed on your system.

### Installation

1. Clone the repository:
    ```bash
    git clone https://github.com/rofeeqshittu/3d-maze-quest.git
    ```

2. Navigate to the project directory:
    ```bash
    cd 3d-maze-quest
    ```

3. Follow the setup instructions in the section below to build and run the game.

## How to Run the Game

To compile and run the game, use the following command in your terminal:

```bash
make
./3d-maze-quest
```

## Project Structure

### Source Code

The core game logic is written in C and can be found in the [`src`](./src) folder:
- [`main.c`](./src/main.c): Handles SDL initialization, window creation, and the main game loop.
- [`player.c`](./src/player.c): Manages player movement and interactions.
- [`raycasting.c`](./src/raycasting.c): Implements the raycasting algorithm.
- [`world.c`](./src/world.c): Handles the game's world and map structure.

### Header Files

The corresponding header files for the source code are located in the [`inc`](./inc) folder:
- [`player.h`](./inc/player.h)
- [`raycasting.h`](./inc/raycasting.h)
- [`world.h`](./inc/world.h)

### Assets

The project’s assets, including images and textures, are stored in the [`images`](./images) folder. You can view them in:
- [`images/`](./images): Contains all in-game assets.

## Contributing

Contributions to the project are welcome! Please check the `CONTRIBUTING.md` file for guidelines on how to get involved.

## Related Projects
- old 3D wolfein game

## License

This project is licensed under the MIT License. See the `LICENSE` file for details..
