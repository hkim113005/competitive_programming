#include <iostream>

using namespace std;

int main() {
    int n, E[10000][4], N[10000][4], a = 0, b = 0, min[10000], cnt[10000];

    cin >> n;

    for (int i = 0; i <= n; i++) {
        cnt[i] = 0;
    }

    for (int i = 0; i < n; i++) {
        char t1;
        int t2, t3;

        cin >> t1 >> t2 >> t3;

        if (t1 == 'E') {
            E[a][0] = t2;
            E[a][1] = t3;
            E[a][2] = i;
            a++;
        }
        else {
            N[b][0] = t2;
            N[b][1] = t3;
            N[b][2] = i;
            b++;
        }

        min[i] = -1;
    }

    for (int i = 0; i < a; i++) {
        for (int j = 0; j < a - 1; j++) {
            if (E[j][1] > E[j + 1][1]) {
                int tmp = E[j][0];
                E[j][0] = E[j + 1][0];
                E[j + 1][0] = tmp;

                tmp = E[j][1];
                E[j][1] = E[j + 1][1];
                E[j + 1][1] = tmp;

                tmp = E[j][2];
                E[j][2] = E[j + 1][2];
                E[j + 1][2] = tmp;
            }
        }
    }

    for (int i = 0; i < b; i++) {
        for (int j = 0; j < b - 1; j++) {
            if (N[j][0] > N[j + 1][0]) {
                int tmp = N[j][0];
                N[j][0] = N[j + 1][0];
                N[j + 1][0] = tmp;

                tmp = N[j][1];
                N[j][1] = N[j + 1][1];
                N[j + 1][1] = tmp;

                tmp = N[j][2];
                N[j][2] = N[j + 1][2];
                N[j + 1][2] = tmp;
            }
        }
    }

    for (int i = 0; i < a; i++) {
        for (int j = 0; j < b; j++) {
            int dif = N[j][0] - E[i][0];

            if (dif > min[N[j][2]] && min[N[j][2]] != -1) {
                dif = min[N[j][2]];
            }

            if (dif >= 0) {
                if (E[i][1] < N[j][1] + dif && E[i][1] >= N[j][1]) {
                    if (min[E[i][2]] > dif || min[E[i][2]] == -1) {
                        min[E[i][2]] = dif;
                        cnt[N[j][2]]++;
                        cnt[N[j][2]] += cnt[E[i][2]];
                    }
                } else if (E[i][1] > N[j][1] + dif && (dif <= min[E[i][2]] || min[E[i][2]] == -1)) {
                    if (min[N[j][2]] > E[i][1] - N[j][1] || min[N[j][2]] == -1) {
                        min[N[j][2]] = E[i][1] - N[j][1];
                        cnt[E[i][2]]++;
                        cnt[E[i][2]] += cnt[N[j][2]];
                    }
                }
            }
        }
    }

    for (int i = 0; i < n; i++) {
        cout << cnt[i] << endl;
    }

    return 0;
}