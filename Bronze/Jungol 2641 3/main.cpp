#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;

int main() {
    int n, c, m, ans = 0;
    vector<tuple<int, int ,int>> d;

    cin >> n >> c >> m;

    d.resize(m);

    for (int i = 0; i < m; i++) {
        cin >> get<1>(d[i]) >> get<0>(d[i]) >> get<2>(d[i]);
    }

    sort(d.begin(), d.end());

    vector<int> a(n);

    for (int i = 0; i < n; i++) {
        a[i] = 0;
    }

    for (int i = 0; i < m; i++) {
        int min_box = -1;

        for (int j = get<1>(d[i]); j < get<0>(d[i]); j++) {
            int t = c - a[j];

            if (t >= get<2>(d[i])) {
                if (get<2>(d[i]) < min_box || min_box == -1) {
                    min_box = get<2>(d[i]);
                }
            }
            else {
                if (t < min_box || min_box == -1) {
                    min_box = t;
                }
            }
        }

        for (int j = get<1>(d[i]); j < get<0>(d[i]); j++) {
            a[j] += min_box;
        }

        ans += min_box;
    }

    cout << ans;

    return 0;
}
