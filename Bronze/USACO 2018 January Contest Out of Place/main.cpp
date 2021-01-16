#include <iostream>
#include <stdio.h>
#include <fstream>

using namespace std;

int main() {
    freopen("outofplace.in", "r", stdin);
    freopen("outofplace.out", "w", stdout);

    bool exist = false, change = true;
    int n = 0, cnt = 0, ans = 0, tmp = 0;
    int a[1000], b[1000];
    scanf("%i", &n);
    for (int i = 0; i < n; i++) {
        scanf("%i", &a[i]);
        for (int j = 0; j < cnt; j++) {
            if (a[i] == b[j]) {
                exist = true;
            }
        }
        if (b[cnt - 1] > a[i]) {
            exist = false;
        }
        if (!exist) {
            b[cnt] = a[i];
            cnt++;
        }
        exist = false;
    }
    while (change) {
        change = false;
        for (int i = 0; i < cnt - 1; i++) {
            if (b[i] > b[i + 1]) {
                tmp = b[i];
                b[i] = b[i + 1];
                b[i + 1] = tmp;
                change = true;
                ans++;
            }
        }
    }
    printf("%d\n", ans);
}
