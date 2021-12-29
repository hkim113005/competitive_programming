#include <iostream>

#define INF 1000000000

using namespace std;

int N, M, K;
int S[100005];
int e[30][30];
int E[30][30];
int mem[100005][30];

void fw() {
    for (int k = 0; k < M; k++) {
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < M; j++) {
                if (E[i][j] > E[i][k] + E[k][j]) E[i][j] = E[i][k] + E[k][j];
            }
        }
    }
}

int cost(int x, int y, int c) {
    int sum = 0;
    for (int i = x; i <= y; i++) {
        sum += E[S[i]][c];
    }
    return sum;
}

int dp(int x, int c) {
    if (mem[x][c] != -1) return mem[x][c];

    int res = INF;

    if (x == 0) {
        return mem[x][c] = 0;
    }

    if (x < K - 1) {
        return INF;
    }

    if (x != K - 1) {
        res = min(res, dp(x - 1, c) + cost(x, x, c));
    }
    
    for (int i = 0; i < M; i++) {
        if (i == c) continue;
        res = min(res, dp(x - K, i) + cost(x - K + 1, x, c));
    }

    return mem[x][c] = res;
}

int main() {
    freopen("cowmbat.in", "r", stdin);
    freopen("cowmbat.out", "w", stdout);

    cin >> N >> M >> K;
    for (int i = 0; i < N; i++) {
        char tmp;
        cin >> tmp;
        S[i] = tmp - 'a';
        for (int j = 0; j < M; j++) {
            mem[i][j] = -1;
        }
    }
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < M; j++) {
            cin >> e[i][j];
            E[i][j] = e[i][j];
        }
    }

    fw();

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < M; j++) {
            //cout << E[i][j] << " ";
        }
        //cout << endl;
    }

    int ans = INF;
    for (int i = 0; i < M; i++) {
        ans = min(ans, dp(N - 1, i));
    }
    cout << ans;

    return 0;
}
