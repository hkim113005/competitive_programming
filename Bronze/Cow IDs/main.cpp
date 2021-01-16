#include <iostream>

using namespace std;

string ans;
int k, n, cnt = 0;

void process(string b) {
    if (cnt == n) {
        ans = b;
        return;
    }

    for (int i = b.length() - 1; i > 0; i--) {
        if (b[i] == '1' && b[i - 1] == '0') {
            int cur = b.length();
            int one = 0;
            string next;

            for (int j = 0; j < i - 1; j++) {
                next += b[j];
                if (b[j] == '1') {
                    one++;
                }
            }

            next += '1';
            next += '0';
            one++;

            for (int j = 0; j < cur - i - 1 - (k - one); j++) {
                next += '0';
            }

            for (int j = 0; j < k - one; j++) {
                next += '1';
            }

            cnt++;

            return process(next);
        }
    }

    int cur = b.length();
    string next;

    next += '1';

    for (int i = 0; i < cur - (k - 1); i++) {
        next += '0';
    }

    for (int i = 0; i < k - 1; i++) {
        next += '1';
    }

    cnt++;

    return process(next);
}

int main() {
    string a;

    cin >> n >> k;

    for (int i = 0; i < k; i++) {
        a += '1';
    }

    process(a);

    cout << ans;

    return 0;
}
