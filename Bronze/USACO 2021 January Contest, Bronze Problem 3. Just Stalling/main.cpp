#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    long long ans = 1;

    vector<int> a;
    vector<int> b;

    cin >> n;

    a.resize(n);
    b.resize(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }

    sort(a.begin(), a.end(), greater<>());

    for (int i = 0; i < n; i++) {
        long long cur = 0;

        for (int j = 0; j < n; j++) {
            int d1 = a[i];
            int d2 = b[j];
            if (a[i] <= b[j]) {
                cur++;
            }
        }

        cur -= i;

        ans *= cur;
    }

    cout << ans;

    return 0;
}
