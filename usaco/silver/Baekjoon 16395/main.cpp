#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    long long n, k;

    cin >> n >> k;

    n--;
    k--;

    long double ans = 1;

    for (int i = 1; i <= n; i++) {
        ans *= i;

        if (i <= (n - k)) {
            ans /= i;
        }

        if (i <= k) {
            ans /= i;
        }
    }

    cout << setprecision(0) << showbase << fixed;
    cout << ans << " ";

    return 0;
}
