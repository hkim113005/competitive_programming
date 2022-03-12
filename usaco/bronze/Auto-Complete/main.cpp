#include <iostream>
#include <cstring>
#include <string>
#include <fstream>

using namespace std;

string dict[1000000];

int main() {
    freopen("auto.in", "r", stdin);
    freopen("auto.out", "w", stdout);

    int w, n;

    cin >> w >> n;

    for (int i = 0; i < w; i++) {
        cin >> dict[i];
    }

    for (int i = 0; i < n; i++) {
        int k;
        string partial;

        cin >> k >> partial;

        int m = 0;
        string possible[1000000];

        for (int j = 0; j < w; j++) {
            if (partial.length() <= dict[j].length()) {
                if (partial == dict[j].substr(0, partial.length())) {
                    possible[m] = dict[j];
                    m++;
                }
            }
        }

        for (int j = 0; j < m; j++) {
            bool change = false;

            for (int l = 0; l < m - 1; l++) {
                if (possible[l] > possible[l + 1]) {
                    string tmp = possible[l];
                    possible[l] = possible[l + 1];
                    possible[l + 1] = tmp;
                    change = true;
                }
            }

            if (!change) {
                break;
            }
        }

        bool answer = false;

        for (int j = 0; j < w; j++) {
            if (dict[j] == possible[k - 1]) {
                cout << j + 1 << endl;
                answer = true;
                break;
            }
        }

        if (!answer) {
            cout << -1;
        }
    }

    return 0;
}
