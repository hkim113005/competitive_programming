#include <iostream>

using namespace std;

int n;
int x[10000];
bool dp[1000000000];
int sum = 0;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x[i];
        sum += x[i];
    }

    for (int i = 0; i <= sum; i++) {
        dp[i] = false;
    }
    dp[0] = true;

    for (int i = 0; i < n; i++) {
        for (int j = sum - x[i]; j >= 0; j--) {
            if(dp[j]) dp[j + x[i]] = true;
        }
    }

    int cnt = 0;
    for (int i = 1; i <= sum; i++) {
        if (dp[i]) cnt++;
    }
    cout << cnt << endl;
    for (int i = 1; i <= sum; i++) {
        if (dp[i]) cout << i << " ";
    }
    cout << endl;

    return 0;
}
