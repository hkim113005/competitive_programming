#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

#define first 0
#define second 1
#define index 2

using namespace std;

int n, q;
vector<tuple<int, int, int>> logs;
vector<vector<int>> c;

int main() {
    cin >> n >> q;

    logs.resize(n);

    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> get<first>(logs[i]) >> get<second>(logs[i]) >> tmp;
        get<index>(logs[i]) = i + 1;
    }

    sort(logs.begin(), logs.end());

    vector<int> a;
    int maxs = get<second>(logs[0]);
    a.push_back(get<index>(logs[0]));

    for (int i = 0; i < n - 1; i++) {
        if (maxs >= get<first>(logs[i + 1])) {
            if (maxs < get<second>(logs[i + 1])) {
                maxs = get<second>(logs[i + 1]);
            }
            a.push_back(get<index>(logs[i + 1]));
        }
        else {
            maxs = get<second>(logs[i + 1]);
            sort(a.begin(), a.end());
            c.push_back(a);
            a = vector<int>(0);
            a.push_back(get<index>(logs[i + 1]));
        }
    }

    sort(a.begin(), a.end());
    c.push_back(a);

    for (int i = 0; i < q; i++) {
        int s, t;
        bool in = false;

        cin >> s >> t;

        for (auto & j : c) {
            bool S = binary_search(j.begin(), j.end(), s), T = binary_search(j.begin(), j.end(), t);
            if (S && T) {
                in = true;
                break;
            }
            else if (S || T) {
                break;
            }
        }

        if (in) {
            cout << 1 << endl;
        }
        else {
            cout << 0 << endl;
        }
    }
}