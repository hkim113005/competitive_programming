#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    vector<pair<int, int>> f;

    cin >> n;

    f.resize(n);

    for (int i = 0; i < n; i++) {
        int m, d;

        cin >> m >> d;

        f[i].second = m * 32 + d;

        cin >> m >> d;

        f[i].first = m * 32 + d;
    }

    sort(f.begin(), f.end());

    int cnt = 1, s;

    for (int i = n - 1; i >= 0; i--) {
        if (3 * 32 + 1 >= f[i].second) {
            s = i;
            break;
        }
    }

    while (f[s].first < 12 * 32) {
        bool no = true;

        for (int i = n - 1; i > s; i--) {
            if (f[i].second <= f[s].first) {
                cnt++;
                s = i;
                no = false;
                break;
            }
        }

        if (no) {
            cnt = 0;
            break;
        }
    }

    cout << cnt;

    return 0;
}
