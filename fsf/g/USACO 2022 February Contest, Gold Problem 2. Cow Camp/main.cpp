#include <iostream>
#include <math.h>

using namespace std;

int T, K;
long double P;
long double p[100005];
long double f[100005];
long double q[100005];

int factorial(int x) {
    if (f[x]) return f[x];
    int res = 1;
    for (int i = 2; i <= x; i++) {
        res *= i;
    }
    return f[x] = res;
}

int main() {
    cin >> T >> K;

    for (int i = 1; i <= T / 2; i++) {
        p[i] = p[T - i + 1] = (long double)(factorial(T - 1) / (factorial(i - 1) * factorial(T - 1 - i + 1))) / pow(2, T - 1);
        q[i] = p[i] * i;
        q[T - i + 1] = p[T - i + 1] * (T - i + 1);
        P += p[i] * i + p[T - i + 1] * (T - i + 1);
    }

    //cout << P << endl;

    for (int i = 1; i <= T; i++) {
        for (int j = 1; j < K; j++) {
            if (q[i] - pow(p[i], j) * i + pow(p[i], j) * P > q[i]) q[i] = q[i] - pow(p[i], j) * i + pow(p[i], j) * P;
        }
    }

    long double ans = 0;
    for (int i = 1; i <= T; i++) {
        //cout << q[i] << endl;
        ans += q[i];
    }
    cout << ans << endl;

    return 0;
}
