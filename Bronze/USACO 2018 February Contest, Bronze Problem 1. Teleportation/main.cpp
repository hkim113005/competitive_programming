#include <iostream>
#include <stdio.h>
#include <math.h>
#include <fstream>

int abs(int x) {
    if (x > 0) {
        return x;
    }
    else {
        return -1 * x;
    }
}

int main() {
    freopen("teleport.in", "r", stdin);
    freopen("teleport.out", "w", stdout);

    int a, b, x, y, tmp, min = 1000000;
    scanf("%d %d %d %d", &a, &b, &x, &y);
    if (a > b) {
        tmp = a;
        a = b;
        b = tmp;
    }
    if (x > y) {
        tmp = x;
        x = y;
        y = tmp;
    }
    tmp = abs(a - x) + abs(b - y);
    if (tmp < min) {
        min = tmp;
    }
    tmp = abs(b - a);
    if (tmp < min) {
        min = tmp;
    }
    printf("%i\n", min);
    return 0;
}
