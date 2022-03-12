#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<pair<int, int>> r;

int main() {
    cin >> n;

    r.resize(n);

    for (int i = 0; i < n; i++) {
        cin >> r[i].second >> r[i].first;
    }

    sort(r.begin(), r.end());

    int x = 0, cnt = 1;

    for (int i = 1; i < n; i++) {
        if (r[x].first <= r[i].second) {
            cnt++;
            x = i;
        }
    }

    cout << cnt;

    return 0;
}
