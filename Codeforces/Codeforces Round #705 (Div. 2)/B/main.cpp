#include <iostream>

using namespace std;

int flip(int a) {
    if (a == 1) {
        return 1;
    }
    if (a == 2) {
        return 5;
    }
    if (a == 5) {
        return 2;
    }
    if (a == 8) {
        return 8;
    }
    if (a == 0) {
        return 0;
    }
    return 100000;
}

void solve() {
    int H, M;

    cin >> H >> M;

    int h1, h2, m1, m2;
    string t;

    cin >> t;

    h1 = t[0] - '0';
    h2 = t[1] - '0';
    m1 = t[3] - '0';
    m2 = t[4] - '0';

    int h = h1 * 10 + h2;
    int m = m1 * 10 + m2;
    int nh;
    int nm;

    nh = flip(m2) * 10 + flip(m1);
    nm = flip(h2) * 10 + flip(h1);

    while (h1 == 3 || h1 == 4 || h1 == 6 || h1 == 7 || h1 == 9 || h2 == 3 || h2 == 4 || h2 == 6 || h2 == 7 || h2 == 9 || m1 == 3 || m1 == 4 || m1 == 6 || m1 == 7 || m1 == 9 || m2 == 3 || m2 == 4 || m2 == 6 || m2 == 7 || m2 == 9 || nh >= H || nm >= M) {
        m++;

        if (m >= M) {
            m = 0;
            h++;
        }

        if (h >= H) {
            h = 0;
        }

        h1 = h / 10;
        h2 = h % 10;
        m1 = m / 10;
        m2 = m % 10;

        nh = flip(m2) * 10 + flip(m1);
        nm = flip(h2) * 10 + flip(h1);
    }

    cout << h1 << h2 << ':' << m1 << m2 << endl;
}

int main() {
    int T;

    cin >> T;

    while (T--) {
        solve();
    }

    return 0;
}
