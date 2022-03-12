#include <iostream>

using namespace std;

int main() {
    int N;
    bool p, q;
    string s;

    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> s;

        p = true;
        q = true;

        int x, y;
        x = y = 0;

        for (int j = 0; j < s.length() / 2; j++) {
            if (s[j + x] != s[s.length() - 1 - j]) {
                if (x == 1) {
                    p = false;
                    break;
                }

                if (s[j + 1] == s[s.length() - 1 - j]) {
                    x = 1;
                    j--;
                    continue;
                }

                p = false;
                break;
            }
        }

        for (int j = 0; j < s.length() / 2; j++) {
            if (s[j] != s[s.length() - 1 - j - y]) {
                if (y == 1) {
                    q = false;
                    break;
                }

                if (s[j] == s[s.length() - 1 - j - 1]) {
                    y = 1;
                    j--;
                    continue;
                }

                q = false;
                break;
            }
        }

        if ((p && x == 0) || (q && y == 0)) {
            cout << 0 << endl;
            continue;
        } else if (p || q) {
            cout << 1 << endl;
            continue;
        } else {
            cout << 2 << endl;
        }
    }
}
