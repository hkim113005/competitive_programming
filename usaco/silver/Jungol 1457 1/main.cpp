#include <iostream>
#include <algorithm>

using namespace std;

int M, N, K, ans[10000], cnt = 0;
bool box[105][105];

void process(int x, int y) {
        /*
        for (int a = 0; a < M; a++) {
            for (int b = 0; b < N; b++) {
                cout << box[a][b] << " ";
            }
            cout << endl;
        }

        cout << endl << endl;
        */

        bool end = true;

        box[x][y] = true;

        if (x - 1 >= 0) {
            if (!box[x - 1][y]) {
                ans[cnt]++;
                process(x - 1, y);
                end = false;
            }
        }

        if (x + 1 < M) {
            if (!box[x + 1][y]) {
                ans[cnt]++;
                process(x + 1, y);
                end = false;
            }
        }

        if (y - 1 >= 0) {
            if (!box[x][y - 1]) {
                ans[cnt]++;
                process(x, y - 1);
                end = false;
            }
        }

        if (y + 1 < N) {
            if (!box[x][y + 1]) {
                ans[cnt]++;
                process(x, y + 1);
                end = false;
            }
        }

        if (end) {
            return;
        }
}

int main() {
    cin >> M >> N >> K;

    for (int i = 0; i < K; i++) {
        int tx1, tx2, ty1, ty2;

        cin >> tx1 >> ty1 >> tx2 >> ty2;

        for (int j = ty1; j < ty2; j++) {
            for (int k = tx1; k < tx2; k++) {
                box[j][k] = true;
            }
        }
    }

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            if (!box[i][j]) {
                process(i, j);
                cnt++;
            }
        }
    }

    cout << cnt << endl;

    sort(ans, ans + cnt);

    for (int i = 0; i < cnt; i++) {
        cout << ans[i] + 1 << " ";
    }

    cout << endl;

    return 0;
}
