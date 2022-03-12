#include <iostream>
#include <math.h>

typedef struct {
    int x, y;
} cowPos;

int n, cow;
bool cows[1005];
cowPos cow_pos[1005];

bool one_cow() {
    int cnt = 0, index;
    for (int i = 0; i < n; i++) {
        if (cows[i]) {
            cnt++;
            index = i;
        }
        if (cnt > 1) {
            return false;
        }
    }
    cow = index;
    return true;
}

int closest_cow(int x) {
    int min = 25000, index = 0;
    for (int i = 0; i < n; i++) {
        if (i != x) {
            if (cows[i]) {
                int dist = sqrt(abs(cow_pos[x].x - cow_pos[i].x) * abs(cow_pos[x].x - cow_pos[i].x) + abs(cow_pos[x].y - cow_pos[i].y) * abs(cow_pos[x].y - cow_pos[i].y));
                if (dist < min) {
                    min = dist;
                    index = i;
                }
            }
        }
    }
    return index;
}

int main() {
    for (int i = 0; i < 1005; i++) {
        cows[i] = false;
    }

    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        cows[i] = true;
        scanf("%d %d", &cow_pos[i].x, &cow_pos[i].y);
    }

    while (!one_cow()) {
        for (int i = 0; i < n; i++) {
            if (cows[i]) {
                cows[closest_cow(i)] = false;
            }
        }
    }

    printf("%d", cow + 1);
}

/*
4
0 0
100 200
500 800
-300 400
 */
