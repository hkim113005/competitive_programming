#include <iostream>
#include <math.h>

using namespace std;

typedef int64_t ll;

ll n;
ll m = 1000000007;

int main() {
    cin >> n;

    ll ans = 0;
    for (ll i = 1, s = sqrt(n); i <= s; i++) {
        ll t = (n / i) % m;
        ans += t * i + ((s + t + 1) * (t - s)) / 2;
        ans %= m;
    }

    cout << ans << endl;

    return 0;
}