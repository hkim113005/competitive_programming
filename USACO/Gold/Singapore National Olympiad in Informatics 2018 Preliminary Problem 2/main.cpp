#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int S, N;
int V[100005], W[100005], K[100005];
vector<pair<int, int>> weights[2005];
int dp[2005];

int main() {
    cin >> S >> N;
    for (int i = 0; i < N; i++) {
        cin >> V[i] >> W[i] >> K[i];
        weights[W[i]].emplace_back(make_pair(V[i], K[i]));
    }

    for (int i = 0; i <= S;  i++) {
        if (weights[i].empty()) continue;
        sort(weights[i].begin(), weights[i].end(), greater<>());
        int weight_idx = 0;
        for (int j = 0; j * i < S; j++) {
            if (weight_idx >= weights[i].size()) break;
            for (int k = S; k >= i; k--) {
                dp[k] = max(dp[k], dp[k - i] + weights[i][weight_idx].first);
            }
            weights[i][weight_idx].second--;
            if (weights[i][weight_idx].second == 0) weight_idx++;
        }
    }

    cout << dp[S] << endl;

    for (int i = 0; i <= S; i++) {
        //cout << dp[i] << " ";
    }
    //cout << endl;

    return 0;
}
