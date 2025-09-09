#ifndef SNAKEGAME_H
#define SNAKEGAME_H

#define WIDTH 20    // Width of the grid
#define HEIGHT 20   // Height of the grid

// Directions
typedef enum { UP, DOWN, LEFT, RIGHT } Direction;

// Snake structure
typedef struct {
    int x[WIDTH * HEIGHT]; // X-coordinates of the snake body
    int y[WIDTH * HEIGHT]; // Y-coordinates of the snake body
    int length;            // Length of the snake
    Direction dir;         // Current direction of movement
} Snake;

// Food structure
typedef struct {
    int x, y; // Coordinates of the food
} Food;

// Function prototypes
void initializeGame(Snake *snake, Food *food, int *score);
void drawGame(const Snake *snake, const Food *food, int score);
void updateGame(Snake *snake, Food *food, int *score, int *gameOver);
void changeDirection(Snake *snake, char input);
int checkCollision(const Snake *snake);

#endif
