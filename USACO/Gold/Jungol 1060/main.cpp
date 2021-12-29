#include <iostream>

using namespace std;

int N;
int prices[105][105], check[105][105], node[105];

int kruskal() {
    int MIN, x, y, ans = 0;

    for (int i = 1; i < N;) {
        MIN = 100005;

        for (int j = 1; j < N; j++) {
            for (int k = j + 1; k <= N; k++) {
                if (prices[j][k] < MIN && !check[j][k]) {
                    MIN = prices[j][k];

                    x = j;
                    y = k;
                }
            }
        }

        check[x][y] = 1;

        x = node[x];
        y = node[y];

        if (x == y) {
            continue;
        }

        ans += MIN;

        i++;

        for (int j = 1; j <= N; j++) {
            if (node[j] == x) {
                node[j] = y;
            }
        }
    }

    return ans;
}

int main() {
    cin >> N;

    for (int i = 1; i <= N; i++) {
        node[i] = i;

        for (int j = 1; j <= N; j++) {
            cin >> prices[i][j];
        }
    }

    cout << kruskal();

    return 0;
}