#include <iostream>
#include <stdio.h>
#include <fstream>

typedef struct coord {
    long long x;
    long long y;
};

coord coords[40005];
long long length = 0;

bool exists(long long x, long long y) {
    for (long long i = 0; i < length; i++) {
        if (x == coords[i].x && y == coords[i].y) {
            return true;
        }
    }
    return false;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    long long x1, x2, y;

    scanf("%i", &n);
    for (int i = 0; i < n; i++) {
        scanf("%lld %lld %lld", &x1, &x2, &y);
        for (long long j = x1; j < x2; j++) {
            for (long long k = 0; k < y; k++) {
                if (!exists(j, k)) {
                    coords[length].x = j;
                    coords[length].y = k;
                    length++;
                    if (length > 1000000) {
                        printf("A");
                        return 0;
                    }
                }
            }
        }
    }
    printf("%lld", length);
}
