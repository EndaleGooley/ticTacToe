#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

char board[9] ={'1', '2', '3', '4', '5', '6', '7', '8', '9'};

void displayBoard() {

cout << "     |     |     \n";
cout << "  " << board[0] << "  |  " << board[1] << "  |  " << board[2] << "  \n";
cout << "_____|_____|_____\n";
cout << "     |     |     \n";
cout << "  " << board[3] << "  |  " << board[4] << "  |  " << board[5] << "  \n";
cout << "_____|_____|_____\n";
cout << "     |     |     \n";
cout << "  " << board[6] << "  |  " << board[7] << "  |  " << board[8] << "  \n";
cout << "     |     |     \n";
}

void playerMove(char mark) {
    int move;
    cout << "Enter the position (1-9) where you want to place your mark (" << mark << "): ";
    cin >> move;
    if (move >= 1 && move <= 9 && board[move -1] != 'X' && board[move - 1] != 'O') {
        board[move - 1] = mark;
    }
    else {
        cout << "Invaild move! Try again. \n";
        playerMove(mark);
    }
}

bool checkWin() {
    int winCombos[8][3] = {
        {0, 1, 2}, {3, 4, 5}, {6, 7, 8},
        {0, 3 ,6}, {1, 4, 7}, {2, 5, 8},
        {0, 4, 8}, {2, 4, 6}
    };
    for (int i = 0; i < 8; i++) {
        if (board[winCombos[i][0]] == board[winCombos[i][1]] && board[winCombos[i][1]] == board[winCombos[i][2]]) {
            return true;
        }
    }
    return false;
}

bool checkTie() {
    for (int i = 0; i < 9; i++) {
        if (board[i] != 'X' && board[i] != 'O') {
            return false;
        }
    }
    return true;
}

void aiMove(char aiMark, char playerMark) {
    for (int i = 0; i < 9; i++){
        if (board[i] != 'X' && board[i] != 'O') {
            board[i] = aiMark;
            if (checkWin()) {
                return;
            }
        board[i] = '0' + (i + 1);
        }
    }
    for (int i = 0; i < 9; i++) {
        if  (board[i] != 'X' && board[i] != 'O') {
            board[i] = aiMark;
            if(checkWin()) {
                board[i] = aiMark;
                return;
            }
            board[i] = '0' + (i + 1);
        }
    }
    srand(time(0));
    int move;
    while (true) {
        move = rand() % 9;
        if (board[move] != 'X' && board[move] != 'O') {
            board[move] = aiMark;
            break;
        }
    }
    cout << "AI choose position: " << move + 1 << "\n";
}

void game() {
    char player = 'X';
    char ai = 'O';

    while (true) {
        displayBoard();

        if(player == 'X') {
        playerMove(player);
        }
        else {
        aiMove(ai, player);
        }
        if (checkWin()) {
        displayBoard();
        cout << "Player " << player << " wins!\n";
        break;
        }
        else if (checkTie()) {
        displayBoard();
        cout << "Its a tie!\n";
        break;
        }
        player = (player == 'X') ? ai : 'X';
    }
}

int main() {
    cout << "Welcome to TIC-TAC-TOE!\n";
    game();
    return 0;
}