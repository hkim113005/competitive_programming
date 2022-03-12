#include <iostream>

#define INF (int)1e9

using namespace std;

int n, x;
int c[10000000];
int dp[10000000];

int main() {
    cin >> n >> x;
    for (int i = 0; i < n; i++) {
        cin >> c[i];
    }
    for (int i = 0; i <= x; i++) {
        dp[i] = INF;
    }

    dp[0] = 0;
    for (int i = 0; i <= x; i++) {
        for (int j = 0; j < n; j++) {
            if (i - c[j] >= 0) {
                dp[i] = min(dp[i], dp[i - c[j]] + 1);
            }
        }
    }

    cout << (dp[x] >= INF ? -1 : dp[x]) << endl;

    return 0;
}
