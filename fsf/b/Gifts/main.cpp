#include <iostream>

using namespace std;

int main() {
    int n, b, p[1005], s[1005], ps[1005];

    cin >> n >> b;

    for (int i = 0; i < n; i++) {
        cin >> p[i] >> s[i];
        ps[i] = p[i] + s[i];
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - 1; j++) {
            if (ps[j] > ps[j + 1]) {
                int tmp = ps[j];
                ps[j] = ps[j + 1];
                ps[j + 1] = tmp;

                tmp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = tmp;

                tmp = s[j];
                s[j] = s[j + 1];
                s[j + 1] = tmp;
            }
        }
    }

    int cnt = 0;
    bool coupon = true;

    for (int i = 0; i < n; i++) {
        if (b - ps[i] < 0) {
            if (coupon) {
                int max_price = 0;

                for (int j = 0; j <= cnt; j++) {
                    if (p[j] > max_price) {
                        max_price = p[j];
                    }
                }

                if (b - ps[i] + max_price / 2 < 0) {
                    int k = 0;
                }
                else {
                    b -= ps[i] + max_price / 2;
                    cnt++;
                    coupon = false;
                }
            }
            else {
                break;
            }
        }
        else {
            b -= ps[i];
            cnt++;
        }
    }

    cout << cnt << endl;
}

/*
10 200
24 43
4352 53
532 53
44 4
2 1
46 1
34 635
4 53
4 5
20 10
 */
