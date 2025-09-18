#include <iostream>

using namespace std;

char b[9] = {'1','2','3','4','5','6','7','8','9'};
char player = 'X';
int m;

// Function to display the board
void showBoard() {
    for (int i = 0; i < 9; i++) {
        cout << b[i] << " ";
        if ((i + 1) % 3 == 0) {
            cout << endl;
        }
    }
}

// Function to take player move
void move() {
    cout << "Player " << player << "'s turn, enter move from (1-9): ";
    cin >> m;
    if (m < 1 || m > 9) {
        cout << "Invalid move! Position out of range. Try again.\n";
        move();
    }
    else if (b[m - 1] == 'X' || b[m - 1] == 'O') {
        cout << "Invalid move! Position already taken. Try again.\n";
        move();
    }
    else {
        b[m - 1] = player;
    }
}

// Function to check if a player has won
bool win() {
    return (b[0] == b[1] && b[1] == b[2]) ||
           (b[3] == b[4] && b[4] == b[5]) ||
           (b[6] == b[7] && b[7] == b[8]) ||
           (b[0] == b[3] && b[3] == b[6]) ||
           (b[1] == b[4] && b[4] == b[7]) ||
           (b[2] == b[5] && b[5] == b[8]) ||
           (b[0] == b[4] && b[4] == b[8]) ||
           (b[2] == b[4] && b[4] == b[6]);
}

// Function to check for a draw
bool draw() {
    for (auto c : b) {
        if (c != 'X' && c != 'O') return false;
    }
    return true;
}

// Switch player turns
void switchplayer() {
    player = (player == 'X') ? 'O' : 'X';
}

// Main game function
void game() {
    while (true) {
        showBoard();
        move();
        if (win()) {
            showBoard();
            cout << "Player " << player << " won!\n";
            break;
        }
        if (draw()) {
            showBoard();
            cout << "It's a draw!\n";
            break;
        }
        switchplayer();
    }
}

int main() {
    game();
    return 0;
}
