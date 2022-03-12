#include <iostream>
#include <queue>

using namespace std;

int t, n, a[300005];

void solve() {
    priority_queue<int, vector<int>, greater<>> q;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        q.push(a[i]);
    }
    int cnt = 0;
    for (int i = 0; i < n; i++) {

    }

    int b[300005];
    int x = 0;
    for (int i = 0; i < n; i++) b[i] = 0;
    for (int i = 0; i < n; i++) {
        int tmp = q.top();
        q.pop();
        if (tmp != q.top()) x++;
    }
    cout << endl;
}

int main() {
    cin >> t;
    while (t--) solve();

    return 0;
}
