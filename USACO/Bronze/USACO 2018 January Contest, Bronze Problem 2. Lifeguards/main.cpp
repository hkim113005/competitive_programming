#include <iostream>
#include <stdio.h>
#include <fstream>

int main() {
    freopen("lifeguards.in", "r", stdin);
    freopen("lifeguards.out", "w", stdout);

    int n, a[101][2], min = 1001, max = 0, ans = 0, cnt = 0;
    bool t[1001];
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &a[i][0], &a[i][1]);
    }
    for (int i = 0; i < n; i++) {
        min = 1001;
        max = 0;
        cnt = 0;
        for (int j = 0; j < 1001; j++) {
            t[i] = false;
        }
        for (int j = 0; j < n; j++) {
            if (j != i) {
                for (int k = a[j][0]; k < a[j][1]; k++) {
                    t[k] = true;
                }
                if (a[j][0] < min) {
                    min = a[j][0];
                }
                if (a[j][1] > max) {
                    max = a[j][1];
                }
            }
        }
        for (int j = min; j < max; j++) {
            if (!t[j]) {
                if (cnt > ans) {
                    ans = cnt;
                }
                cnt = 0;
            }
            cnt++;
        }
        if (cnt > ans) {
            ans = cnt;
            cnt = 0;
        }
    }
    printf("%d", ans + 1);
}
