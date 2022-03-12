#include <iostream>
#include <vector>

#define INF -1000000000

using namespace std;

long long N, K;
vector<long long> edges[100005];
long long colors[100005][4];
bool tra[100005];

long long solve(long long cur, long long col) {
    long long ans = 1;
    bool end = true;

    if (colors[cur][col] != INF) return colors[cur][col];

    tra[cur] = true;

    for (long long i = 0; i < edges[cur].size(); i++) {
        bool change = false;
        long long sum = 0;
        for (long long j = 1; j <= 3; j++) {
            if (!tra[edges[cur][i]] && j != col) {
                sum += solve(edges[cur][i], j);
                sum %= 1000000007;
                if (end) end = false;
                change = true;
            }
        }
        if (change) ans *= sum;
        ans %= 1000000007;
    }

    if (end) ans = 1;

    tra[cur] = false;

    return colors[cur][col] = ans;
}

int main() {
    freopen("barnpainting.in", "r", stdin);
    freopen("barnpainting.out", "w", stdout);

    cin >> N >> K;

    for (long long i = 1; i <= N; i++) {
        colors[i][1] = colors[i][2] = colors[i][3] = INF;
        tra[i] = false;
    }

    for (long long i = 0; i < N - 1; i++) {
        long long a, b;

        cin >> a >> b;

        edges[a].emplace_back(b);
        edges[b].emplace_back(a);
    }

    for (long long i = 0; i < K; i++) {
        long long a, b;

        cin >> a >> b;

        for (long long j = 1; j <= 3; j++) {
            if (j == b) colors[a][b] = INF;
            else colors[a][j] = 0;
        }
    }

    cout << (((solve(1, 1) % 1000000007) + (solve(1, 2) % 1000000007) % 1000000007) + (solve(1, 3) % 1000000007)) % 1000000007 << endl;

    for (long long i = 1; i <= N; i++) {
        for (long long j = 1; j <= 3; j++) {
            //cout << colors[i][j] << " ";
        }
        //cout << endl;
    }

    return 0;
}
