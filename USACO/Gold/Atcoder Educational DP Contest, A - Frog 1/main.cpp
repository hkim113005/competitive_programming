#include <iostream>
#include <math.h>

#define INF 1000000000

using namespace std;

int N;
int h[200005];
int dp[200005];

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> h[i];
    }

    for (int i = 0; i < N + 100; i++) {
        dp[i] = INF;
        h[i + N] = INF;
    }
    dp[0] = 0;
    for (int i = 0; i < N; i++) {
        dp[i + 1] = min(dp[i + 1], dp[i] + abs(h[i + 1] - h[i]));
        dp[i + 2] = min(dp[i + 2], dp[i] + abs(h[i + 2] - h[i]));
    }

    cout << dp[N - 1];

    return 0;
}
