#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;

int ans[200005], t[200005];

bool sort_by_sec(const tuple<int, int, int>& a, const tuple<int, int, int>& b) {
    return (get<1>(a) < get<1>(b));
}

int main() {
    int N;
    vector<tuple<int, int, int>> v;

    cin >> N;

    v.resize(N);

    for (int i = 0; i < N; i++) {
        cin >> get<0>(v[i]) >> get<1>(v[i]);

        get<2>(v[i]) = i;
    }

    sort(v.begin(), v.end(), sort_by_sec);

    int tot = 0, same = 0;

    for (int i = 0; i < N; i++) {
        if (i > 0) {
            if (get<1>(v[i]) == get<1>(v[i - 1])) {
                same++;
            } else {
                same = 0;
            }
        } else {
            same = 0;
        }
        tot += get<1>(v[i]);
        t[get<0>(v[i])] -= get<1>(v[i]);
        ans[get<2>(v[i])] = t[get<0>(v[i])] + tot - same * get<1>(v[i]);
    }

    for (int i = 0; i < N; i++) {
        cout << ans[i] << endl;
    }

    return 0;
}

