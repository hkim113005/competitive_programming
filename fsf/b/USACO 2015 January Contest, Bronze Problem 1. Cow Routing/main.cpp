#include <iostream>
#include <stdio.h>
#include <fstream>

int main() {
    freopen("cowroute.in", "r", stdin);
    freopen("cowroute.out", "w", stdout);

    int a, b, n, cost, cities, city, min = 100000;
    bool e = false, f = false;
    scanf("%d %d %d", &a, &b, &n);
    for (int i = 0; i < n; i++) {
        e = false;
        f = false;
        scanf("%d %d", &cost, &cities);
        for (int j = 0; j < cities; j++) {
            scanf("%d", &city);
            if (city == a) {
                e = true;
            }
            if (city == b) {
                if (e) {
                    f = true;
                }
            }
        }
        if (e && f) {
            if (cost < min) {
                min = cost;
            }
        }
    }
    if (min == 100000) {
        min = -1;
    }
    printf("%d", min);
}
