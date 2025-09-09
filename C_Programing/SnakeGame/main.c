#include "SnakeGame.c"

int main() {
    Snake snake;
    Food food;
    int score, gameOver = 0;

    initializeGame(&snake, &food, &score);

    while (!gameOver) {
        if (_kbhit()) {
            char input = _getch();
            changeDirection(&snake, input);
        }

        updateGame(&snake, &food, &score, &gameOver);
        drawGame(&snake, &food, score);

        _sleep(200); // Control the speed of the game
    }

    printf("\nGame Over! Your final score was: %d\n", score);
    return 0;
}
