#include <iostream>
#include <string>

using namespace std;

int n, m, maxlen = 0;
char board[25][25];

bool ok(char a, string b) {
    for (int i = 0; i < b.length(); i++) {
        if (b[i] == a) {
            return false;
        }
    }

    return true;
}

void process(string word, int x, int y) {
    if (x - 1 >= 0) {
        if (ok(board[x - 1][y], word)) {
            word += board[x - 1][y];
            process(word, x - 1, y);
            word.pop_back();
        }
    }

    if (x + 1 < n) {
        if (ok(board[x + 1][y], word)) {
            word += board[x + 1][y];
            process(word, x + 1, y);
            word.pop_back();
        }
    }

    if (y - 1 >= 0) {
        if (ok(board[x][y - 1], word)) {
            word += board[x][y - 1];
            process(word, x, y - 1);
            word.pop_back();
        }
    }

    if (y + 1 < m) {
        if (ok(board[x][y + 1], word)) {
            word += board[x][y + 1];
            process(word, x, y + 1);
            word.pop_back();
        }
    }

    if (word.size() > maxlen) {
        maxlen = word.length();
    }
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
        }
    }

    string t = "";
    t += board[0][0];

    process(t, 0, 0);

    cout << maxlen << endl;

    return 0;
}
