#include <stdio.h>
#include <stdlib.h>
#include <conio.h> // For _kbhit() and _getch()
#include <time.h>
#include "SnakeGame.h"

// Initialize the game
void initializeGame(Snake *snake, Food *food, int *score) {
    snake->length = 1;
    snake->x[0] = WIDTH / 2; // Start snake in the middle
    snake->y[0] = HEIGHT / 2;
    snake->dir = RIGHT;

    // Initialize food at a random position
    srand(time(NULL));
    food->x = rand() % WIDTH;
    food->y = rand() % HEIGHT;

    *score = 0;
}

// Draw the game grid
void drawGame(const Snake *snake, const Food *food, int score) {
    system("cls"); // Clear the screen

    // Draw top border
    for (int i = 0; i < WIDTH + 2; i++) printf("#");
    printf("\n");

    // Draw the grid
    for (int y = 0; y < HEIGHT; y++) {
        printf("#"); // Left border
        for (int x = 0; x < WIDTH; x++) {
            if (x == snake->x[0] && y == snake->y[0]) {
                printf("O"); // Snake's head
            } else if (x == food->x && y == food->y) {
                printf("F"); // Food
            } else {
                int isBody = 0;
                for (int i = 1; i < snake->length; i++) {
                    if (x == snake->x[i] && y == snake->y[i]) {
                        printf("o"); // Snake's body
                        isBody = 1;
                        break;
                    }
                }
                if (!isBody) printf(" ");
            }
        }
        printf("#\n"); // Right border
    }

    // Draw bottom border
    for (int i = 0; i < WIDTH + 2; i++) printf("#");
    printf("\n");

    // Display the score
    printf("Score: %d\n", score);
}

// Update the game state
void updateGame(Snake *snake, Food *food, int *score, int *gameOver) {
    // Move the snake's body
    for (int i = snake->length - 1; i > 0; i--) {
        snake->x[i] = snake->x[i - 1];
        snake->y[i] = snake->y[i - 1];
    }

    // Move the head
    switch (snake->dir) {
        case UP:    snake->y[0]--; break;
        case DOWN:  snake->y[0]++; break;
        case LEFT:  snake->x[0]--; break;
        case RIGHT: snake->x[0]++; break;
    }

    // Check for collision with walls or itself
    *gameOver = checkCollision(snake);

    // Check if the snake eats the food
    if (snake->x[0] == food->x && snake->y[0] == food->y) {
        snake->length++;
        (*score)++;

        // Generate new food
        food->x = rand() % WIDTH;
        food->y = rand() % HEIGHT;
    }
}

// Change the direction of the snake
void changeDirection(Snake *snake, char input) {
    switch (input) {
        case 'w': if (snake->dir != DOWN)  snake->dir = UP;    break;
        case 's': if (snake->dir != UP)    snake->dir = DOWN;  break;
        case 'a': if (snake->dir != RIGHT) snake->dir = LEFT;  break;
        case 'd': if (snake->dir != LEFT)  snake->dir = RIGHT; break;
    }
}

// Check for collision
int checkCollision(const Snake *snake) {
    // Check collision with walls
    if (snake->x[0] < 0 || snake->x[0] >= WIDTH || snake->y[0] < 0 || snake->y[0] >= HEIGHT) {
        return 1;
    }

    // Check collision with itself
    for (int i = 1; i < snake->length; i++) {
        if (snake->x[0] == snake->x[i] && snake->y[0] == snake->y[i]) {
            return 1;
        }
    }

    return 0;
}
