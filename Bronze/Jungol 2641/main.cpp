#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;

int main() {
    int t, n, m;
    vector<tuple<int, int, int>> d;

    cin >> t >> m >> n;

    d.resize(n);

    for (int i = 0; i < n; i++) {
        cin >> get<0>(d[i]) >> get<1>(d[i]) >> get<2>(d[i]);
    }

    sort(d.begin(), d.end());

    int cur = 0, tot = 0;

    for (int i = 1; i <= t; i++) {
        for (int j = 0; j < n; j++) {
            if (get<0>(d[j]) == i) {
                if (get<2>(d[j]) > m) {
                    get<2>(d[j]) = m;
                }
                if (cur + get<2>(d[j]) <= m) {
                    tot += get<2>(d[j]);
                    cur += get<2>(d[j]);
                }
            }

            if (get<1>(d[j]) == i) {
                cur -= get<2>(d[j]);
            }
        }
    }

    cout << tot;

    return 0;
}
