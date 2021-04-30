#include <iostream>

using namespace std;

long long mem[40] { 0 };

long long t(int n) {
    if (mem[n] != 0) {
        return mem[n];
    }

    if (n == 0) {
        return 1;
    }

    long long x = 0;

    for (int i = 0; i <= n - 1; i++) {
        if (mem[i] == 0) {
            mem[i] = t(i);
        }

        if (mem[n - 1 - i] == 0) {
            mem[n - 1 - i] = t(n - 1 - i);
        }

        x += mem[i] * mem[n - 1 - i];
    }

    mem[n] = x;

    return x;
}

int main() {
    int n;

    cin >> n;

    cout << t(n);

    return 0;
}
