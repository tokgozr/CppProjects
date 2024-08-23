#include <iostream>

using namespace std;

const int SIZE = 3;
char board[SIZE][SIZE] = {{'1', '2', '3'},
                          {'4', '5', '6'},
                          {'7', '8', '9'}};

void drawBoard() {
    cout << endl;
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            cout << " " << board[i][j];
            if (j < SIZE - 1) cout << " |";
        }
        cout << endl;
        if (i < SIZE - 1) cout << "---|---|---" << endl;
    }
    cout << endl;
}

bool checkWinner(char player){
    for (int i = 0; i < SIZE; i++)
    {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player)
            return true;
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player)
            return true;
    }

    if (board[0][0] == player && board [1][1] == player && board[2][2] == player)
        return true;
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player)
        return true;

    return false;
}

bool isMoveValid(int move){
    return move >= 1 && move <= 9 && board[(move-1)/SIZE][(move-1)%SIZE] != 'X' && board[(move-1)/SIZE][(move-1)%SIZE] != 'O';
}

void makeMove(char player){
    int move;
    bool valid = false;

    do{
        cout << "Player " << player << ", enter your move (1-9): ";
        cin >> move;

        // Check if the input is not an integer
        if (cin.fail()) {
            cin.clear();  // Clear the error flags
            cin.ignore(1000, '\n');  // Ignore the invalid input in the buffer
            cout << "Invalid input, please enter a number between 1 and 9." << endl;
            continue;  // Skip to the next iteration of the loop
        }

        valid = isMoveValid(move);
        if (!valid) {
            cout << "Invalid move, please try again." << endl;
        }
    }
    while (!valid);

    board[(move-1)/SIZE][(move-1)%SIZE] = player;
}

bool checkDraw(){
    for (int i = 0; i< SIZE; i++)
    {
        for(int j = 0; j < SIZE; j++)
        {
            if (board[i][j] != 'X' && board[i][j] != 'O'){
                return false;
            }
        }
    }
    return true;
}

int main(){
    char player = 'X';
    bool gameOn = true;

    while (gameOn){
        drawBoard();
        makeMove(player);

        if (checkWinner(player)){
            drawBoard();
            cout << "Player " << player << " wins!" << endl;
            gameOn = false;
        }
        else if (checkDraw()){
            drawBoard();
            cout << "It's a draw!" << endl;
            gameOn = false;
        }
        else{
            player = (player == 'X') ? 'O' : 'X';
        }
    }
    return 0;
}
