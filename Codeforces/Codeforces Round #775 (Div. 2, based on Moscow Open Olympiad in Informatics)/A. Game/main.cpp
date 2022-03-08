#include <iostream>

using namespace std;

int t, n;
int a[105];

void solve() {
    cin >> n;
    bool zero = false;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (!a[i]) zero = true;
    }
    if (!zero) {
        cout << 0 << endl;
        return;
    }
    int i = 0;
    while (a[i + 1] && i < n) {
        i++;
    }
    int j = n - 1;
    while (a[j - 1] && j > 0) {
        j--;
    }
    cout << j - i << endl;
}

int main() {
    cin >> t;
    while(t) {
        solve();
        t--;
    }

    return 0;
}
