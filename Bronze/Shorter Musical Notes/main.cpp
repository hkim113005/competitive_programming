#include <iostream>

int main() {
    int n, q, time[1200000], idx = 0;

    scanf("%d %d", &n, &q);

    for (int i = 0; i < n; i++) {
        int t;
        scanf("%d", &t);

        for (int j = 0; j < t; j++) {
            time[idx] = i + 1;
            idx++;
        }
    }

    for (int i = 0; i < q; i++) {
        int t;
        scanf("%d", &t);

        printf("%d\n", time[t]);
    }

    return 0;
}
