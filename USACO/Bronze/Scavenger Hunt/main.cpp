#include <iostream>

int main() {
    int n, m;

    scanf("%d %d", &n, &m);

    for (int i = 1; i < n + 1; i++) {
        if (n % i == 0) {
            for (int j = 1; j < m + 1; j++) {
                if (m % j == 0) {
                    printf("%d %d\n", i, j);
                }
            }
        }
    }

    return 0;
}
