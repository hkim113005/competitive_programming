#include <iostream>
#include <stack>

using namespace std;

int t;
int n;
int a[10005];

void shift(int d, int x) {
    int new_a[10005];
    bool loop = false;
    for (int i = 0; i < x; i++) {
        int j = (a[i + 1] - d + x) % (x);
        if (j == 0) new_a[i + 1] = x;
        else new_a[i + 1] = j;
    }
    for (int i = 1; i <= x; i++) {
        a[i] = new_a[i];
    }
}

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int tmp;
        cin >> tmp;
        a[tmp] = i;
    }

    stack<int> ans;
    for (int i = n; i >= 1; i--) {
        int d = a[i] - i;
        if (d < 0) d += i;
        shift(d, i);
        ans.push(d);
    }

    while (!ans.empty()) {
        cout << ans.top() << " ";
        ans.pop();
    }
    cout << endl;
}

int main() {
    cin >> t;
    while (t--) solve();
    return 0;
}
