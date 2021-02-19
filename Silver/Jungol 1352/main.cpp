#include <iostream>

using namespace std;

int n, m;
int weights[40];
int marbles[10];
char ans[10];

void input() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> weights[i];
    }

    cin >> m;

    for (int i = 0; i < m; i++) {
        cin >> marbles[i];
    }
}

char dynamic(int marble) {
    int total = 0;
    int w[505];

    for (int i = 0; i <= 500; i++) {
        w[i] = 0;
    }

    for (int i = 0; i <= 500; i++) {
        for (int j = 0; j < n; j++) {
            if (i == weights[j]) {
                w[i]++;
                total += i;
            }
        }
    }

    bool possible[60000];

    for (int i = 0; i < 60000; i++) {
        possible[i] = false;
    }

    possible[0] = true;

    bool go = true;

    while (go) {
        go = false;

        for (int i = 0; i <= 500; i++) {
            if (w[i] > 0) {
                go = true;

                for (int j = total; j >= i; j--) {
                    if (possible[j - i]) {
                        possible[j] = true;
                    }
                }

                w[i]--;
            }
        }
    }

    for (int i = 0; i < total; i++) {
        if (possible[i] && possible[i + marble]) {
            return 'Y';
        }
    }

    return 'N';
}

int main() {
    input();

    for (int i = 0; i < m; i++) {
        cout << dynamic(marbles[i]) << ' ';
    }

    cout << endl;

    return 0;
}
