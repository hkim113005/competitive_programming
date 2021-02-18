#include <iostream>

using namespace std;

int a_len = 0;
int a[50];
string n;
int ans = 1;

void input() {
    cin >> n;

    int cnt = 0;
    bool b = true;

    for (int i = 0; i < n.length(); i++) {
        int d = ((n[i] - '0') * 10 + n[i + 1] - '0');

        if (d <= 34 && d % 10 != 0) {
            cnt++;
        }
        else if (d % 10 == 0 && d / 10 <= 3 && d / 10 != 0) {
            a[a_len] = cnt;

            a_len++;

            cnt = 0;

            i++;
        }
        else if (d % 10 == 0) {
            cout << 0;

            exit(0);
        }
        else if (d > 34) {
            a[a_len] = cnt + 1;

            a_len++;

            cnt = 0;
        }
    }

    if (cnt != 0) {
        a[a_len] = cnt;

        a_len++;
    }
}

void dynamic() {
    int f[50];

    f[0] = 1;
    f[1] = 1;

    for (int i = 2; i < n.length(); i++) {
        f[i] = f[i - 1] + f[i - 2];
    }

    for (int i = 0; i < a_len; i++) {
        ans *= f[a[i]];
    }
}

void output() {
    cout << ans;
}

int main() {
    input();

    dynamic();

    output();

    return 0;
}
