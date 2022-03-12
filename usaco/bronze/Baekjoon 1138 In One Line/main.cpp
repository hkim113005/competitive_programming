#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<pair<int, int>> l;

int main() {
    cin >> n;

    l.resize(n);

    for (int i = 0; i < n; i++) {
        l[i].first = i + 1;
        cin >> l[i].second;
    }

    sort(l.begin(), l.end(), greater<pair<int, int>());

    vector<int> ans { l[0].first };

    for (int i = 0; i < n; i++) {
        auto it = ans.insert(l.begin(), l[i].first);
    }
    return 0;
}
