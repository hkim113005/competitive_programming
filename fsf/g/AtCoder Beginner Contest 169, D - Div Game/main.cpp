#include <iostream>

using namespace std;

typedef long long ll;

ll N;
ll prime[10000000];
ll d[10000000];

int main() {
    cin >> N;

    int p = 0;
    for (ll i = 2; i * i <= N; i++) {
        while (N % i == 0) {
            prime[p]++;
            N /= i;
        }
        p++;
    }
    if (N != 1) {
        prime[p]++;
        p++;
    }

    for (ll i = 0; i < p; i++) {
        d[i] = 1;
    }

    ll ans = 0;
    for (ll i = 0; i < p; i++) {
        while (prime[i] >= d[i]) {
            ans++;
            prime[i] -= d[i];
            d[i]++;
        }
    }

    cout << ans << endl;

    return 0;
}
