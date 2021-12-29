#include <iostream>
#include <vector>
#include <string>

using namespace std;

int n, m, cnt = 0;
vector<string> A;
vector<string> B;

pair<int, int> next(int x) {
    int cnt = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (A[i][j] != B[i][j]) {
                if (x == cnt) {
                    return make_pair(i, j);
                }
                else {
                    cnt++;
                }
            }
        }
    }

    if (cnt != 0) {
        return make_pair(-2, -2);
    }

    return make_pair(-1, -1);
}

void change(pair<int, int> pos) {
    for (int i = pos.first; i < pos.first + 3; i++) {
        for (int j = pos.second; j < pos.second + 3; j++) {
            if (A[i][j] == '0') {
                A[i][j] = '1';
            }
            else {
                A[i][j] = '0';
            }
        }
    }
}

int main() {
    cin >> n >> m;

    A.resize(n);
    B.resize(n);

    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    for (int i = 0; i < n; i++) {
        cin >> B[i];
    }

    int x = 0;

    while (true) {
        pair<int, int> pos = next(x);

        if (pos.first == -1 && pos.second == -1) {
            break;
        }

        if (pos.first == -2 && pos.second == -2) {
            cnt = -1;
            break;
        }

        if (cnt > (n - 1) * (m - 1)) {
            cnt = -1;
            break;
        }

        x++;

        if (pos.first + 3 <= n && pos.second + 3 <= m) {
            x = 0;
            cnt++;

            change(pos);
        }
    }


    cout << cnt;

    return 0;
}
