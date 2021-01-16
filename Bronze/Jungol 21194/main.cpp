#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

int main() {
    //freopen("input.in", "r", stdin);
    //freopen("output.out", "w", stdout);

    int n, s;
    vector<pair<int, int>> week;

    cin >> n >> s;

    week.resize(n);

    for (int i = 0; i < n; i++) {
        cin >> week[i].first >> week[i].second;
    }

    long long ans = 0;
    int bp = 1000000000, sbp = 0;

    for (int i = 0; i < n; i++) {
        ans += min(bp + s * sbp, week[i].first) * week[i].second;

        if (week[i].first <= bp + s * sbp) {
            bp = week[i].first;
            sbp = 1;
        }
        else {
            sbp++;
        }
    }

    cout << ans;

    return 0;
}
