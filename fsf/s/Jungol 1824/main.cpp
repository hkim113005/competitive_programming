#include <iostream>

using namespace std;

int board[10][10];
bool row_check[10][10], col_check[10][10], box_check[10][10];

void sudoku(int x, int y) {
    if (x > 8) {
        sudoku(0, y + 1);
    }

    if (y > 8) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                cout << board[j][i] << " ";
            }

            cout << endl;
        }

        exit(0);
    }

    if (board[x][y] != 0) {
        sudoku(x + 1, y);
        return;
    }
    else {
        for (int i = 1; i <= 9; i++) {
            if (!row_check[y][i] && !col_check[x][i] && !box_check[(x / 3) * 3 + y / 3][i]) {
                board[x][y] = i;
                row_check[y][i] = col_check[x][i] = box_check[(x / 3) * 3 + y / 3][i] = true;
                sudoku(x + 1, y);
                row_check[y][i] = col_check[x][i] = box_check[(x / 3) * 3 + y / 3][i] = false;
                board[x][y] = 0;
            }
        }
    }
}

int main() {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cin >> board[j][i];

            row_check[i][board[j][i]] = col_check[j][board[j][i]] = box_check[(j / 3) * 3 + i / 3][board[j][i]] = true;
        }
    }

    sudoku(0, 0);

    return 0;
}
