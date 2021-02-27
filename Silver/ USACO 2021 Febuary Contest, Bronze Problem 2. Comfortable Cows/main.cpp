#include <iostream>

using namespace std;

int N;
int field[1005][1005];
bool cows[1005][1005];

int main() {
    cin >> N;

    int cnt = 0;

    for (int i = 0; i < N; i++) {
        int x, y;

        cin >> x >> y;

        cows[x][y] = true;

        if (x - 1 >= 0) {
            field[x - 1][y]++;

            if (field[x - 1][y] == 3 && cows[x - 1][y]) {
                cnt++;
            }
        }

        if (x + 1 <= 1000) {
            field[x + 1][y]++;

            if (field[x + 1][y] == 3 && cows[x + 1][y]) {
                cnt++;
            }
        }

        if (y - 1 >= 0) {
            field[x][y - 1]++;

            if (field[x][y - 1] == 3 && cows[x][y - 1]) {
                cnt++;
            }
        }

        if (y + 1 <= 1000) {
            field[x][y + 1]++;

            if (field[x][y + 1] == 3 && cows[x][y + 1]) {
                cnt++;
            }

        }

        cout << cnt << endl;
    }

    return 0;
}
