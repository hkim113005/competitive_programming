#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int t, n;
vector<pair<int, int>> a;

int main() {
    cin >> t;

    for (int i = 0; i < t; i++) {
        cin >> n;

        a = vector<pair<int, int>>(0);
        a.resize(n);

        for (int j = 0; j < n; j++) {
            cin >> a[j].first >> a[j].second;
        }

        sort(a.begin(), a.end());

        int x = a[0].first, y = a[0].second, cnt = 1;

        for (int j = 1; j < n; j++) {
            if (a[j].first < x || a[j].second < y) {
                if (x < a[j].first) {
                    x = a[j].first;
                }

                if (y > a[j].second) {
                    y = a[j].second;
                }
                cnt++;
            }
        }

        cout << cnt << endl;
    }

    return 0;
}
