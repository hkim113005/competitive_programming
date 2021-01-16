#include <iostream>
#include <vector>

using namespace std;

int board[9][9];
vector<int> tried[9][9];

vector<int> possible(int x, int y) {
    bool numbers[10];

    for (int i = 1; i <= 9; i++) {
        numbers[i] = true;
    }

    for (int i = 0; i < 9; i++) {
        if (i != y) {
            numbers[board[x][i]] = false;
        }
    }

    for (int i = 0; i < 9; i++) {
        if (i != x) {
            numbers[board[i][y]] = false;
        }
    }

    int gx = (x / 3) * 3, gy = (y / 3) * 3;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (gx + i != x && gy + j != y) {
                numbers[board[gx + i][gy + j]] = false;
            }
        }
    }

    vector<int> r;

    for (int i = 1; i <= 9; i++) {
        if (numbers[i]) {
            r.push_back(i);
        }
    }

    return r;
}

bool ok() {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (board[i][j] == 0) {
                return false;
            }
        }
    }

    return true;
}

bool process() {
    if (ok()) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                cout << board[i][j] << " ";
            }

            cout << endl;
        }

        exit(0);
    }

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cout << board[i][j] << " ";
        }

        cout << endl;
    }

    cout << endl << endl;

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (board[i][j] == 0) {
                vector<int> next = possible(i, j);

                if (next.size() == 0) {
                    return false;
                }

                for (int k = 0; k < next.size(); k++) {
                    if (count(tried[i][j].begin(), tried[i][j].end(), next[k]) == 0) {
                        board[i][j] = next[k];
                        process();
                        board[i][j] = 0;
                    }
                }
            }
        }
    }
}

int main() {
    int x = 5, y = 3;

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cin >> board[i][j];
        }
    }

    /*
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (i == x && j == y) {
                cout << "X ";
            }
            else {
                cout << board[i][j] << " ";
            }
        }

        cout << endl;
    }

    vector<int> next = possible(x, y);

    for (int i = 0; i < next.size(); i++) {
        cout << next[i] << " ";
    }
     */

    process();

    return 0;
}

/*
0 0 0 1 2 3 0 0 0
0 0 0 4 5 6 0 0 0
0 0 0 7 0 9 0 0 0
1 2 3 5 4 7 0 0 0
4 5 6 2 9 1 0 0 0
0 8 9 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0
 */