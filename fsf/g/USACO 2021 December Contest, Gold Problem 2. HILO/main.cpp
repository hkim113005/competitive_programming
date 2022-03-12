#include <iostream>

using namespace std;

int N;
int E[200005];

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> E[i];
    }

    for (int i = 0; i <= N; i++) {
        int hi = -1, lo = -1;
        int ans = 0;
        int s[200005];
        for (int j = 0; j < N; j++) {
            s[j] = 0;
        }
        for (int j = 0; j < N; j++) {
            if (i < E[j]) {
                if (hi == -1 || E[j] < hi) {
                    hi = E[j];
                    s[j] = 1;
                }
            }
            else {
                if (lo == -1 || E[j] > lo) {
                    lo = E[j];
                    s[j] = 2;
                }
            }
        }
        for (int j = 0; j < N - 1; j++) {
            if (s[j] == 1 && s[j + 1] == 2) ans++;
        }
        cout << ans << endl;
    }
}


/*
int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> E[i];
    }

    for (int i = 0; i < N - 1; i++) {
        if (E[i] > E[i + 1]) {
            bool go = true;
            for (int j = E[i + 1] + 1; j < E[i]; j++) {
                if (b[j]) {
                    go = false;
                    break;
                }
            }
            if (go) {
                for (int j = E[i + 1]; j < E[i]; j++) {
                    ans[j]++;
                }
            }
        }
        b[E[i]] = b[E[i + 1]] = true;
    }

    for (int i = 0; i <= N; i++) {
        cout << ans[i] << endl;
    }

    return 0;
}
*/