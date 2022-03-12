#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

char board[5][5];
vector<string> possible;

void check(const string& a) {
    bool in = false;

    for (int i = 0; i < possible.size(); i++) {
        if (possible[i] == a) {
            in = true;
        }
    }

    if (!in) {
        possible.push_back(a);
    }

    return;
}

void process(string a, int x, int y, int cnt) {
    if (cnt == 5) {
        check(a);

        return;
    }

    if (x - 1 >= 0) {
        process(a + board[x - 1][y], x - 1, y, cnt + 1);
    }

    if (x + 1 < 5) {
        process(a + board[x + 1][y], x + 1, y, cnt + 1);
    }

    if (y - 1 >= 0) {
        process(a + board[x][y - 1], x, y - 1, cnt + 1);
    }

    if (y + 1 < 5) {
        process(a + board[x][y + 1], x, y + 1, cnt + 1);
    }
}

int main() {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cin >> board[i][j];
        }
    }

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            string tmp;
            tmp += board[i][j];
            process(tmp, i, j, 0);
        }
    }

    cout << possible.size() << endl;

    //sort(possible.begin(), possible.end());

    for (int i = 0; i < possible.size(); i++) {
        //cout << possible[i] << endl;
    }

    return 0;
}
