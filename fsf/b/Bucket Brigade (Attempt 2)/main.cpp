#include <iostream>
#include <math.h>

typedef struct pos{
    int x, y;
};

pos b, l, r;

int main() {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            char tmp;
            scanf("%c", &tmp);
            if (tmp == 10) {
                scanf("%c", &tmp);
            }
            if (tmp == 'B') {
                b.x = i;
                b.y = j;
            }
            if (tmp == 'L') {
                l.x = i;
                l.y = j;
            }
            if (tmp == 'R') {
                r.x = i;
                r.y = j;
            }
        }
    }

    if (b.x != l.x && b.y != l.y) {
        printf("%d", abs(b.x - l.x) + abs(b.y - l.y ) - 1);
    }
    else if (b.x == l.x) {
        if (b.x == r.x) {
            if ((b.y < r.y && r.y < l.y) || (l.y < r.y && r.y < b.y)) {
                printf("%d", abs(b.y - l.y) + 1);
            }
            else {
                printf("%d", abs(b.y - l.y) - 1);
            }
        }
        else {
            printf("%d", abs(b.y - l.y) - 1);
        }
    }
    else if (b.y == l.y) {
        if (b.y == r.y) {
            if ((b.x < r.x && r.x < l.x) || (l.x < r.x && r.x < b.x)) {
                printf("%d", abs(b.x - l.x) + 1);
            }
            else {
                printf("%d", abs(b.x - l.x) - 1);
            }
        }
        else {
            printf("%d", abs(b.x - l.x) - 1);
        }
    }
}
