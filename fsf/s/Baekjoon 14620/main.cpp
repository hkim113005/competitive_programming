#include <iostream>

using namespace std;

int n;
int a[20][20];
int ans = -1;

void print(int b[20][20]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << b[i][j] << " ";
        }

        cout << endl;
    }

    cout << endl << endl;
}

void process(int cnt, int b[20][20], int tot) {
    if (cnt == 3) {
        if (tot < ans || ans == -1) {
            //print(b);
            ans = tot;
        }

        return;
    }

    for (int i = 1; i < n - 1; i++) {
        for (int j = 1; j < n - 1; j++) {
            if (b[i][j] != -1 && b[i - 1][j] != -1 && b[i + 1][j] != -1 && b[i][j - 1] != -1 && b[i][j + 1] != -1) {
                int c[20][20];

                for (int k = 0; k < 20; k++) {
                    for (int l = 0; l < 20; l++) {
                        c[k][l] = b[k][l];
                    }
                }

                int add = 0;

                add += c[i][j];
                add += c[i - 1][j];
                add += c[i + 1][j];
                add += c[i][j - 1];
                add += c[i][j + 1];

                c[i][j] = -1;
                c[i - 1][j] = -1;
                c[i + 1][j] = -1;
                c[i][j - 1] = -1;
                c[i][j + 1] = -1;

                process(cnt + 1, c, tot + add);
            }

        }
    }
}

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }

    process(0, a, 0);

    cout << ans;

    return 0;
}
