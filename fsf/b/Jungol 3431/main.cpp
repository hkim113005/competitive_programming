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

    /*
    for (int i = 0; i < n; i++) {
        cout << get<first>(logs[i]) << " " << get<second>(logs[i]) << " " << get<index>(logs[i]) << endl;
    }
     */

    vector<int> a;
    a.push_back(get<index>(logs[0]));

    for (int i = 0; i < n - 1; i++) {
        if (get<second>(logs[i]) >= get<first>(logs[i + 1])) {
            a.push_back(get<index>(logs[i + 1]));
        }
        else {
            c.push_back(a);
            a = vector<int>(0);
            a.push_back(get<index>(logs[i + 1]));
        }
    }

    c.push_back(a);

    /*
    for (int i = 0; i < c.size(); i++) {
        for (int j = 0; j < c[i].size(); j++) {
            cout << c[i][j] << " ";
        }
        cout << endl;
    }
     */

    for (int i = 0; i < q; i++) {
        int s, t;
        bool in = false;

        cin >> s >> t;

        for (int j = 0; j < c.size(); j++) {
            bool S, T;
            S = T = false;

            for (int k = 0; k < c[j].size(); k++) {
                if (c[j][k] == s) {
                    S = true;
                }
                if (c[j][k] == t) {
                    T = true;
                }
            }

            if (S && T) {
                in = true;
            }
        }

        if (in) {
            cout << 1 << endl;
        }
        else {
            cout << 0 << endl;
        }
    }

    return 0;
}
