#include <iostream>

using namespace std;

int main() {
    int n, x, y, z, a[20000][2], min = 1000000000, max = 0, ans = 0;

    cin >> n >> x >> y >> z;

    for (int i = 0; i < n; i++) {
        cin >> a[i][0] >> a[i][1];

        if (min > a[i][0]) {
            min = a[i][0];
        }

        if (max < a[i][1]) {
            max = a[i][1];
        }
    }

    for (int i = min - 1; i <= max + 1; i++) {
        int p = 0, q = 0, r = 0;

        for (int j = 0; j < n; j++) {
            if (a[j][0] <= i && i <= a[j][1]) {
                q++;
            }
            else if (i < a[j][0]) {
                p++;
            }
            else if (i > a[j][1]) {
                r++;
            }
        }

        int tmp = p * x + q * y + r * z;

        if (ans < tmp) {
            ans = tmp;
        }
    }

    cout << ans << endl;

    return 0;
}
