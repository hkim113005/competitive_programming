#include <iostream>
#include <algorithm>

using namespace std;

int n, ans[900], cnt = 0;
bool apartment[30][30];

void print() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << apartment[i][j] << " ";
        }
        cout << endl;
    }

    cout << endl << endl;
}

void process(int x, int y) {
    //print();

    apartment[x][y] = false;

    if (x - 1 >= 0) {
        if (apartment[x - 1][y]) {
            ans[cnt]++;
            process(x - 1, y);
        }
    }

    if (x + 1 < n) {
        if (apartment[x + 1][y]) {
            ans[cnt]++;
            process(x + 1, y);
        }
    }

    if (y - 1 >= 0) {
        if (apartment[x][y - 1]) {
            ans[cnt]++;
            process(x, y - 1);
        }
    }

    if (y + 1 < n) {
        if (apartment[x][y + 1]) {
            ans[cnt]++;
            process(x, y + 1);
        }
    }
}

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        string tmp;

        cin >> tmp;

        for (int j = 0; j < tmp.length(); j++) {
            apartment[i][j] = tmp[j] - '0';
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (apartment[i][j]) {
                process(i, j);
                cnt++;
            }
        }
    }

    sort(ans, ans + cnt);

    cout << cnt << endl;

    for (int i = 0; i < cnt; i++) {
        cout << ans[i] + 1 << endl;
    }

    return 0;
}
