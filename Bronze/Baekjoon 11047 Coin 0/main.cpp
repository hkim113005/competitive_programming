#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, k, cnt = 0;
vector<int> coins;

int main() {
    cin >> n >> k;

    coins.resize(n);

    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }

    sort(coins.begin(), coins.end());

    for (int i = n - 1; i >= 0; i--) {
        cnt += k / coins[i];
        k -= k / coins[i] * coins[i];
    }

    cout << cnt << endl;

    return 0;
}
