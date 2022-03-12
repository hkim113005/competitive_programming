#include <iostream>

int n, a[25][25];
int cnt[625], cntcnt = 0;

int main() {
    bool first = true;
    char tmp[10000];
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s", tmp);
        for (int j = 0; j < n; j++) {
            if (tmp[j] == '1') {
                a[i][j] = 1;
            }
            else if (tmp[j] == '0') {
                a[i][j] = 0;
            }

            if (a[i][j] == 1 && first) {
                a[i][j] = -1;
                cnt[0] = 1;
                first = false;
            }
        }
    }

    while (true) {
        for (int i = 0; i < n * n; i++) {
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < n; k++) {
                    if (a[j][k] == 1) {
                        if (j > 0) {
                            if (a[j - 1][k] == -1) {
                                cnt[cntcnt]++;
                                a[j][k] = -1;
                                break;
                            }
                         }
                        if (j < n - 1) {
                            if (a[j + 1][k] == -1) {
                                cnt[cntcnt]++;
                                a[j][k] = -1;
                                break;
                            }
                        }
                        if (k > 0) {
                            if (a[j][k - 1] == -1) {
                                cnt[cntcnt]++;
                                a[j][k] = -1;
                                break;
                            }
                        }
                        if (k < n - 1) {
                            if (a[j][k + 1] == -1) {
                                cnt[cntcnt]++;
                                a[j][k] = -1;
                                break;
                            }
                        }
                    }
                }
            }
        }

        /*
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                printf("%2d ", a[i][j]);
            }
            printf("\n");
        }
        printf("\n\n");
        */

        first = true;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (a[i][j] == 1 && first) {
                    a[i][j] = -1;
                    cnt[cntcnt + 1] = 1;
                    first = false;
                }
            }
        }

        if (cnt[cntcnt] == 0) {
            break;
        }

        cntcnt++;
    }

    for (int i = 0; i < cntcnt; i++) {
        for (int j = 1; j < cntcnt; j++) {
            if (cnt[j - 1] > cnt[j]) {
                int tmp = cnt[j - 1];
                cnt[j - 1] = cnt[j];
                cnt[j] = tmp;
            }
        }
    }

    printf("%d\n", cntcnt);
    for (int i = 0; i < cntcnt; i++) {
        printf("%d\n", cnt[i]);
    }
}
