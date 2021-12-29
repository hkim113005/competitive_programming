#include <iostream>
#include <algorithm>

using namespace std;

int n;
int x[500005];
bool factors[100000005];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }

    sort(x, x + n);

    int ans = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 1; j * j <= x[i]; j++) {
            if (x[i] % j == 0) {
                if (factors[j]) ans = max(ans, j);
                if (factors[x[i] / j]) ans = max(ans, x[i] / j);
                factors[j] = factors[x[i] / j] = true;
            }
        }
    }

    cout << ans << endl;

    return 0;
}
