#include <iostream>

#define int int64_t

using namespace std;

int n;

int pow(int b, int e, int m) {
    if (e == 0) return 1;

    int res = pow(b, e / 2, m);
    res = (res * res) % m;
    if (e % 2) res = (res * b) % m;

    return res;
}

int32_t main() {
    //freopen("test.in", "r", stdin);
    //freopen("test.out", "w", stdout);

    cin >> n;

    for (int i = 0; i < n; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        cout << pow(a, pow(b, c, 1e9 + 6), 1e9 + 7) << endl;
    }

    return 0;
}
