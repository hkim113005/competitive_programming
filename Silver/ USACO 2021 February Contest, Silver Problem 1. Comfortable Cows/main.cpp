#include <iostream>

using namespace std;

int N;
int field[2005][2005];
bool cows[2005][2005];
int cnt = 0;

void process(int px, int py) {
    int x, y;

    if (!cows[px - 1][py]) {
        x = px - 1;
        y = py;
    }
    else if (!cows[px + 1][py]) {
        x = px + 1;
        y = py;
    }
    else if (!cows[px][py - 1]) {
        x = px;
        y = py - 1;
    }
    else if (!cows[px][py + 1]) {
        x = px;
        y = py + 1;
    }

    cows[x][y] = true;

    field[x - 1][y]++;
    field[x + 1][y]++;
    field[x][y - 1]++;
    field[x][y + 1]++;

    if (field[x][y] == 3 && cows[x][y]) {
        process(x, y);
        cnt++;
    }

    if (field[x - 1][y] == 3 && cows[x - 1][y]) {
        process(x - 1, y);
        cnt++;
    }

    if (field[x + 1][y] == 3 && cows[x + 1][y]) {
        process(x + 1, y);
        cnt++;
    }

    if (field[x][y - 1] == 3 && cows[x][y - 1]) {
        process(x, y - 1);
        cnt++;
    }

    if (field[x][y + 1] == 3 && cows[x][y + 1]) {
        process(x, y + 1);
        cnt++;
    }
}

int main() {
    cin >> N;

    for (int i = 0; i < N; i++) {
        int x, y;

        cin >> x >> y;

        x += 500;
        y += 500;

        if (field[x - 1][y] == 4 && cows[x - 1][y]) {
            cnt--;
        }
        else if (field[x + 1][y] == 4 && cows[x + 1][y]) {
            cnt--;
        }
        else if (field[x][y - 1] == 4 && cows[x][y - 1]) {
            cnt--;
        }
        else if (field[x][y + 1] == 4 && cows[x][y + 1]) {
            cnt--;
        }
        else {
            cows[x][y] = true;

            field[x - 1][y]++;
            field[x + 1][y]++;
            field[x][y - 1]++;
            field[x][y + 1]++;

            if (field[x][y] == 3 && cows[x][y]) {
                process(x, y);
                cnt++;
            }

            if (field[x - 1][y] == 3 && cows[x - 1][y]) {
                process(x - 1, y);
                cnt++;
            }

            if (field[x + 1][y] == 3 && cows[x + 1][y]) {
                process(x + 1, y);
                cnt++;
            }

            if (field[x][y - 1] == 3 && cows[x][y - 1]) {
                process(x, y - 1);
                cnt++;
            }

            if (field[x][y + 1] == 3 && cows[x][y + 1]) {
                process(x, y + 1);
                cnt++;
            }
        }

        cout << cnt << endl;

        /*
        for (int j = 498; j < 498 + 10; j++) {
            for (int k = 498; k < 498 + 10; k++) {
                cout << cows[j][k] << " ";
            }

            cout << "\t";

            for (int k = 498; k < 498 + 10; k++) {
                cout << field[j][k] << " ";
            }

            cout << endl;
        }

        cout << endl << endl;
         */
    }

    return 0;
}
/*
8
2 4
1 3
3 3
1 2
3 2
1 1
3 1
2 3
 */