#include <iostream>

void displayBoard(char board[3][3]) 
{
    std::cout << "Current board state:\n";
    for (int i = 0; i < 3; ++i) 
    {
        for (int j = 0; j < 3; ++j) 
        {
            std::cout << board[i][j];
            if (j < 2) 
                std::cout << " | ";
        }
        std::cout << "\n";
        if (i < 2) std::cout << "--|---|--\n";
    }
}

bool checkWin(char board[3][3], char player) 
{
    for (int i = 0; i < 3; ++i) 
    {
        // Check rows and columns
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||
            (board[0][i] == player && board[1][i] == player && board[2][i] == player)) 
        {
            return true;
        }
    }
    // Check diagonals
    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
        (board[0][2] == player && board[1][1] == player && board[2][0] == player)) 
    {
        return true;
    }
    return false;
}

bool checkDraw(char board[3][3]) 
{
    for (int i = 0; i < 3; ++i) 
    {
        for (int j = 0; j < 3; ++j) 
        {
            if (board[i][j] == ' ') 
            {
                return false;
            }
        }
    }
    return true;
}

void switchPlayer(char &currentPlayer) 
{
    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
}

void resetBoard(char board[3][3]) 
{
    for (int i = 0; i < 3; ++i) 
    {
        for (int j = 0; j < 3; ++j) 
        {
            board[i][j] = ' ';
        }
    }
}

int main() {
    char board[3][3];
    char currentPlayer = 'X';
    bool gameOver = false;
    char playAgain;

    do {
        std::cout<<"Welcome to Tic-Tac-Toe Game!!!";
        resetBoard(board);
        gameOver = false;
        currentPlayer = 'X';

        while (!gameOver) 
        {
            displayBoard(board);
            int row, col;

            std::cout << "Player " << currentPlayer << ", Enter your move (row and column: 1 1): ";
            std::cin >> row >> col;
            
            if (row >= 1 && row <= 3 && col >= 1 && col <= 3 && board[row-1][col-1] == ' ') 
            {
                board[row-1][col-1] = currentPlayer;

                if (checkWin(board, currentPlayer)) 
                {
                    displayBoard(board);
                    std::cout << "Player " << currentPlayer << " wins!\n";
                    gameOver = true;
                } 
                else if (checkDraw(board)) 
                {
                    displayBoard(board);
                    std::cout << "The game is a draw!\n";
                    gameOver = true;
                } 
                else 
                {
                    switchPlayer(currentPlayer);
                }
            } 
            else 
            {
                std::cout << "Invalid move. Try again.\n";
            }
        }

        std::cout << "Do you want to play again? (Y/N): ";
        std::cin >> playAgain;

    } while (playAgain == 'y' || playAgain == 'Y');

    return 0;
}
