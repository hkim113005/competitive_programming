#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;

int n, c, m;
vector<tuple<int, int, int>> d;

int main() {
    cin >> n >> c >> m;

    d.resize(m);

    for (int i = 0; i < m; i++) {
        cin >> get<1>(d[i]) >> get<2>(d[i]) >> get<0>(d[i]);

        if (get<0>(d[i]) > c) {
            get<0>(d[i]) = c;
        }
    }

    sort(d.begin(), d.end());

    int max_ans = 0;

    for (int i = m - 1; i >= 0; i--) {
        vector<int> a(n);

        for (int j = 0; j < n; j++) {
            a[j] = 0;
        }

        int ans = 0;

        for (int j = i; j >= 0; j--) {
            bool good = true;

            for (int k = get<1>(d[j]); k < get<2>(d[j]); k++) {
                if(a[k] + get<0>(d[j]) > c) {
                    good = false;
                    break;
                }
            }

            if (good) {
                ans += get<0>(d[j]);
                for (int k = get<1>(d[j]); k < get<2>(d[j]); k++) {
                    a[k] += get<0>(d[j]);
                }
            }
        }

        if (ans > max_ans) {
            max_ans = ans;
        }
    }

    cout << max_ans;

    return 0;
}
