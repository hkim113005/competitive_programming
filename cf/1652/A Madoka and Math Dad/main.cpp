#include <iostream>

using namespace std;

int t, n;

void solve() {
    cin >> n;
    if (n == 1) {
        cout << 1 << endl;
        return;
    }
    if (n == 2) {
        cout << 2 << endl;
        return;
    }
    if (n % 3 == 1) {
        int sum = 0;
        while (sum < n) {
            cout << 1;
            sum++;
            if (sum >= n) break;
            cout << 2;
            sum += 2;
        }
    }
    else {
        int sum = 0;
        while (sum < n) {
            cout << 2;
            sum += 2;
            if (sum >= n) break;
            cout << 1;
            sum++;
        }
    }
    cout << endl;
}

int main() {
    cin >> t;
    while (t--) solve();
    return 0;
}
