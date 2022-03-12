#include <iostream>
#include <vector>

#define INF (int)1e9

using namespace std;

int N, M, C;
int m[2005];
vector<int> e[5005];
int dp[5005][2005];

int main() {
    freopen("time.in", "r", stdin);
    freopen("time.out", "w", stdout);

    cin >> N >> M >> C;
    for (int i = 1; i <= N; i++) {
        cin >> m[i];
    }
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        e[b].push_back(a);
    }

    for (int i = 0; i <= 2 * M + 5; i++) {
        for (int j = 1; j <= N; j++) {
            dp[i][j] = -INF;
        }
    }
    dp[0][1] = 0;

    for (int i = 1; i <= 2 * M + 5; i++) {
        for (int j = 1; j <= N; j++) {
            for (auto k : e[j]) {
                dp[i][j] = max(dp[i][j], dp[i - 1][k] + C * ((i - 1) * (i - 1) - i * i) + m[j]);
            }
        }
    }

    int ans = 0;
    for (int i = 0; i <= 2 * M + 5; i++) {
        ans = max(ans, dp[i][1]);
    }

    //cout << dp[0][1] << " " << dp[1][2] << " " << dp[2][3] << " " << dp[3][1] << " " << dp[4][2] << " " << dp[5][3] << " " << dp[6][1] << endl;

    cout << ans << endl;

    return 0;
}
