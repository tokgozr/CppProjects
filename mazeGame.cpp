#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

const int WIDTH = 7;
const int HEIGHT = 7;

// Maze layout: '#' is a wall, ' ' is a path, 'P' is the player, 'E' is the exit
char maze[HEIGHT][WIDTH] = {
    {'#', '#', '#', '#', '#', '#', '#'},
    {'#', 'P', ' ', ' ', ' ', '#', '#'},
    {'#', ' ', '#', '#', ' ', '#', '#'},
    {'#', ' ', '#', ' ', ' ', ' ', '#'},
    {'#', ' ', ' ', ' ', '#', ' ', '#'},
    {'#', '#', '#', ' ', '#', 'E', '#'},
    {'#', '#', '#', '#', '#', '#', '#'}
};

// Function to draw the maze
void drawMaze() {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            cout << maze[i][j] << ' ';
        }
        cout << endl;
    }
}

// Function to move the player
bool movePlayer(int dx, int dy) {
    int playerX = -1, playerY = -1;

    // Find the player's current position
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            if (maze[i][j] == 'P') {
                playerX = j;
                playerY = i;
                break;
            }
        }
        if (playerX != -1) break;
    }

    // Calculate the new position
    int newX = playerX + dx;
    int newY = playerY + dy;

    // Check if the new position is within bounds and not a wall
    if (newX >= 0 && newX < WIDTH && newY >= 0 && newY < HEIGHT) {
        if (maze[newY][newX] == ' ') {
            // Move the player to the new position
            maze[playerY][playerX] = ' ';
            maze[newY][newX] = 'P';
        } else if (maze[newY][newX] == 'E') {
            // Player reaches the exit
            maze[playerY][playerX] = ' ';
            maze[newY][newX] = 'P';
            return true; // Game over, player has won
        } else {
            cout << "Can't move there! It's a wall." << endl;
        }
    } else {
        cout << "Out of bounds!" << endl;
    }

    return false;
}

int main() {
    bool gameOver = false;
    char move;

    cout << "Welcome to the Maze Game!" << endl;
    cout << "Navigate using W (up), A (left), S (down), D (right)" << endl;

    while (!gameOver) {
        drawMaze();
        cout << "Enter your move: ";
        cin >> move;

        switch (move) {
            case 'W':
            case 'w':
                gameOver = movePlayer(0, -1); // Move up
                break;
            case 'A':
            case 'a':
                gameOver = movePlayer(-1, 0); // Move left
                break;
            case 'S':
            case 's':
                gameOver = movePlayer(0, 1);  // Move down
                break;
            case 'D':
            case 'd':
                gameOver = movePlayer(1, 0);  // Move right
                break;
            default:
                cout << "Invalid move. Use W, A, S, or D." << endl;
        }

        if (gameOver) {
            cout << "You have reached the exit! Congratulations!" << endl;
        }
    }
    return 0;
}
