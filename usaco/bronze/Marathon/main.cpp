#include <iostream>
#include <math.h>

int main() {
    int n, cp[100000][2], max = 0;

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d %d", &cp[i][0], &cp[i][1]);
    }

    for (int i = 1; i < n - 1; i++) {
        int d1 = abs(cp[i - 1][0] - cp[i][0]) + abs(cp[i - 1][1] - cp[i][1]);
        int d2 = abs(cp[i + 1][0] - cp[i][0]) + abs(cp[i + 1][1] - cp[i][1]);
        int td = d1 + d2;

        int pd = abs(cp[i - 1][0] - cp[i + 1][0]) + abs(cp[i - 1][1] - cp[i + 1][1]);

        int dif = td - pd;

        if (dif > max) {
            max = dif;
        }
    }

    int distance = 0;

    for (int i = 0; i < n - 1; i++) {
        int d = abs(cp[i][0] - cp[i + 1][0]) + abs(cp[i][1] - cp[i + 1][1]);

        distance += d;
    }

    printf("%d", distance - max);
}
