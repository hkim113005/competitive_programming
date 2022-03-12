#include <iostream>

int main() {
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    for (int i = 0; i < 3; i++) {
        int tmp;
        if (a > b) {
            tmp = a;
            a = b;
            b = tmp;
        }
        if (b > c) {
            tmp = b;
            b = c;
            c = tmp;
        }
    }
    int min, max;
    if (a + 1 == b && b + 1 == c) {
        min = 0;
    }
    else if (a + 2 == b || b + 2 == c) {
        min = 1;
    }
    else {
        min = 2;
    }
    int dif;
    if (b - a > c - b) {
        dif = b - a;
    }
    else {
        dif = c - b;
    }
    int cnt = 1, i = 1;
    if (dif == 1) {
        max = 0;
    }
    else if (dif == 2) {
        max = 1;
    }
    else {
        max = dif - 1;
    }
    printf("%d\n%d", min, max);
}
