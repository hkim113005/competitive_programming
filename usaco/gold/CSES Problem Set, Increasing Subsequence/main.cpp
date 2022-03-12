#include <iostream>
#include <vector>

using namespace std;

int n;
vector<int> x;
vector<int> dp;

int main() {
    cin >> n;
    x.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }

    for (int i : x) {
        int pos = lower_bound(dp.begin(), dp.end(), i) - dp.begin();
        if (pos == dp.size()) {
            dp.emplace_back(i);
        }
        else {
            dp[pos] = i;
        }
    }

    cout << dp.size() << endl;

    return 0;
}
