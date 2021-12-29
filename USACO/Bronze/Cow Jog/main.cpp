#include <iostream>

int main() {
    int n, cows[100000][2], spd = 1000000005, cnt = 0;

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d %d", &cows[i][0], &cows[i][1]);
    }

    for (int i = n - 1; i >= 0; i--) {
        if (cows[i][1] <= spd) {
            spd = cows[i][1];
            cnt++;
        }
    }

    printf("%d", cnt);
}
