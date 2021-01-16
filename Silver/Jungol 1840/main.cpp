#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
bool cheese[105][105];
vector<pair<int, int>> melt;
vector<pair<int, int>> traveled;

void find_melt(int x, int y) {
    traveled.push_back(make_pair(x, y));

    if (x - 1 >= 0) {
        if (cheese[x - 1][y]) {
            melt.push_back(make_pair(x - 1, y));
        }
        else {
            if (count(traveled.begin(), traveled.end(), make_pair(x - 1, y)) == 0) {
                find_melt(x - 1, y);
            }
        }
    }

    if (x + 1 <= n) {
        if (cheese[x + 1][y]) {
            melt.push_back(make_pair(x + 1, y));
        }
        else {
            if (count(traveled.begin(), traveled.end(), make_pair(x + 1, y)) == 0) {
                find_melt(x + 1, y);
            }
        }
    }

    if (y - 1 >= 0) {
        if (cheese[x][y - 1]) {
            melt.push_back(make_pair(x, y - 1));
        }
        else {
            if (count(traveled.begin(), traveled.end(), make_pair(x, y - 1)) == 0) {
                find_melt(x, y - 1);
            }
        }
    }

    if (y + 1 <= m) {
        if (cheese[x][y + 1]) {
            melt.push_back(make_pair(x, y + 1));
        }
        else {
            if (count(traveled.begin(), traveled.end(), make_pair(x, y + 1)) == 0) {
                find_melt(x, y + 1);
            }
        }
    }
}

void melt_melt() {
    for (int i = 0; i < melt.size(); i++) {
        cheese[melt[i].first][melt[i].second] = false;
    }
}

bool empty() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (cheese[i + 1][j + 1]) {
                return false;
            }
        }
    }

    return true;
}

int count() {
    int cnt = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (cheese[i][j]) {
                cnt++;
            }
        }
    }

    return cnt;
}

int main() {
    int cnt = 0, ans = 0;

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> cheese[i][j];
        }
    }

    while (true) {
        ans = count();

        melt.resize(0);
        traveled.resize(0);

        find_melt(0, 0);

        melt_melt();

        cnt++;

        if(empty()) {
            break;
        }
    }

    cout << cnt << endl << ans << endl;

    return 0;
}
