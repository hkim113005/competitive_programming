#include <iostream>

using namespace std;

int n = -1, m = -1;
bool map[100][100];

void print() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << map[i][j] << " ";
        }

        cout << endl;
    }

    cout << endl << endl;
}

void process(int x, int y) {
    map[x][y] = false;

    if (x - 1 >= 0) {
        if (map[x - 1][y]) {
            process(x - 1, y);
        }

        if (y - 1 >= 0) {
            if (map[x - 1][y - 1]) {
                process(x - 1, y - 1);
            }
        }

        if (y + 1 < m) {
            if (map[x - 1][y + 1]) {
                process(x - 1, y + 1);
            }
        }
    }

    if (x + 1 < n) {
        if (map[x + 1][y]) {
            process(x + 1, y);
        }

        if (y - 1 >= 0) {
            if (map[x + 1][y - 1]) {
                process(x + 1, y - 1);
            }
        }

        if (y + 1 < m) {
            if (map[x + 1][y + 1]) {
                process(x + 1, y + 1);
            }
        }
    }

    if (y - 1 >= 0) {
        if (map[x][y - 1]) {
            process(x, y - 1);
        }
    }

    if (y + 1 < m) {
        if (map[x][y + 1]) {
            process(x, y + 1);
        }
    }
}

int main() {
    while (!(n == 0 && m == 0)) {
        int cnt = 0;

        cin >> m >> n;

        if (n == 0 && m == 0) {
            break;
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> map[i][j];
            }
        }

        //print();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (map[i][j]) {
                    cnt++;
                    process(i, j);
                    //print();
                }
            }
        }

        cout << cnt << endl;
    }

    return 0;
}
