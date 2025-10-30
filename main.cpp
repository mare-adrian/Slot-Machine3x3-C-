#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

const int N = 3;

// helping functions
bool allEqual(int a, int b, int c) {
    return (a == b) && (b == c);
}

// displaying and generating random numbers
void showAndScramble(int v[N][N]) {
    cout << "\n===== REELS =====\n";
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            v[i][j] = rand() % 7 + 1; // 1..7
            cout << v[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "=================\n\n";
}

// verifying if rows OR the two diagonals have the same number
int countWinningLines(const int m[N][N], int bet) {
    int win = 0;

    // rows
    for (int i = 0; i < N; ++i) {
        if (allEqual(m[i][0], m[i][1], m[i][2])) {
            // payout rule (a ta): symbol * bet * 2
            win += m[i][0] * bet * 2;
        }
    }

    // main diagonal
    if (allEqual(m[0][0], m[1][1], m[2][2])) {
        win += m[0][0] * bet * 2;
    }

    // secondary diagonal
    if (allEqual(m[0][2], m[1][1], m[2][0])) {
        win += m[0][2] * bet * 2;
    }

    return win;
}

int main() {
    srand(time(NULL));

    int v[N][N];
    int bet = -1;
    int balance = 1000;

    cout << "=== SLOT 3x3 ===\n";
    cout << "Starting balance: " << balance << "\n";
    cout << "Enter 0 to exit.\n";

    while (balance > 0) {
        cout << "\nCurrent balance: " << balance << "\n";
        cout << "Place your bet (0 to exit): ";
        if (!(cin >> bet)) {
            cout << "Invalid input. Exiting.\n";
            return 0;
        }
        if (bet == 0) {
            cout << "Goodbye!\n";
            break;
        }
        if (bet < 0 || bet > balance) {
            cout << "Bet must be >= 1 and <= your balance.\n";
            continue;
        }

        balance -= bet;

        // clear console (Windows)
        system("cls");

        showAndScramble(v);

        int win = countWinningLines(v, bet);
        if (win > 0) {
            cout << "You won: " << win << "\n";
        } else {
            cout << "You lost: " << bet << "\n";
        }

        balance += win;
        cout << "New balance: " << balance << "\n";
    }

    cout << "\nFinal balance: " << balance << "\n";
    return 0;
}
