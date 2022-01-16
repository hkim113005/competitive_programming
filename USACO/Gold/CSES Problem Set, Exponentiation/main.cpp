#include <iostream>

#define int int64_t

using namespace std;

int n;
int m = 1e9 + 7;

int pow(int b, int e) {
    if (e == 0) return 1;

    int res = pow(b, e / 2);
    res = (res * res) % m;
    if (e % 2) res = (res * b) % m;

    return res;
}

int32_t main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        cout << pow(a, b) << endl;
    }

    return 0;
}
