#include <iostream>

using namespace std;

bool board[15][15];
int n, maxC = 0;

void print() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << board[i][j] << " ";
        }

        cout << endl;
    }

    cout << endl << endl;
}

void process(int x, int y, bool b[15][15], int cnt) {
    //print();

    bool c[15][15];

    for (int i = 0; i < 15; i++) {
        for (int j = 0; j < 15; j++) {
            c[i][j] = b[i][j];
        }
    }

    int tx, ty;

    if (x > y) {
        tx = x - y;
        ty = 0;
    }
    else {
        ty = y - x;
        tx = 0;
    }

    while (tx < n && ty < n && tx >= 0 && ty >= 0) {
        c[tx][ty] = false;
        tx++;
        ty++;
    }

    tx = y + x;
    ty = 0;

    while (tx >= n || ty >= n) {
        tx--;
        ty++;
    }

    while (tx < n && ty < n && tx >= 0 && ty >= 0) {
        c[tx][ty] = false;
        tx--;
        ty++;
    }


    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (c[i][j]) {
                process(i, j, c, cnt + 1);
            }
        }
    }

    if (cnt > maxC) {
        maxC = cnt;
        return;
    }
}

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i][j]) {
                process(i, j, board, 1);
            }
        }
    }

    cout << maxC;

    return 0;
}
