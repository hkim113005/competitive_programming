#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>

#define INF 1000000000000000000

using namespace std;

int n, m;
vector<pair<long long, long long> > intervals;

bool ok(long long d) {
    int cnt = 0;
    long long prev = -1 * INF;

    for (int i = 0; i < m; i++) {
        while (max(prev + d, intervals[i].first) <= intervals[i].second) {
            prev = max(prev + d, intervals[i].first);
            cnt++;

            if (cnt >= n) {
                break;
            }
        }

        if (cnt >= n) {
            break;
        }
    }

    return (cnt >= n);
}

int main() {
    freopen("socdist.in", "r", stdin);
    freopen("socdist.out", "w", stdout);

    cin >> n >> m;

    intervals.resize(m);

    for (int i = 0; i < m; i++) {
        cin >> intervals[i].first >> intervals[i].second;
    }

    sort(intervals.begin(), intervals.end());

    long long low = 1;
    long long high = 1 * INF;
    long long mid;
    long long ans = -1;

    while (low <= high) {
        mid = (low + high) / 2;

        if (ok(mid)) {
            ans = mid;
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }

    cout << ans;
}