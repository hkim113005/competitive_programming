#include <iostream>

using namespace std;

int main() {
    int n;
    int p[100005];

    cin >> n;

    p[1] = 1;

    for (int i = 2; i <= n; i++) {
        if (i % 2 == 0) {
            p[i] = (p[i - 1] * 2 + 1) % 20100529;
        }
        else {
            p[i] = (p[i - 1] * 2 - 1) % 20100529;
        }
    }

    cout << p[n];

    return 0;
}
