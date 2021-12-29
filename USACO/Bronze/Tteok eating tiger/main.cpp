#include <iostream>

int c = 1, d = 1;

int fibonacci(int f1, int f2, int n) {
    if (n == 1) {
        return 1;
    }
    else if (n == 2) {
        return 1;
    }
    if (f1 == n) {
        c = fibonacci(f1, f2, n - 1) + fibonacci(f1, f2, n - 2);
        return c;
    }
    else if (f2 == n) {
        d = fibonacci(f1, f2, n - 1) + fibonacci(f1, f2, n - 2);
        return d;
    }
    return fibonacci(f1, f2, n - 1) + fibonacci(f1, f2, n - 2);
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    fibonacci(n - 2, n - 1, n - 1);
    for (int i = 1; i < k / c; i++) {
        for (int j = 1; j < k / d; j++) {
            if (k == c * i + d * j) {
                printf("%d\n%d", i, j);
                return 0;
            }
        }
    }
}