#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<int> a;

int main() {
    cin >> n;

    a.resize(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    int ans = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < i; j++) {
            ans += a[j];
        }
    }

    cout << ans;

    return 0;
}
