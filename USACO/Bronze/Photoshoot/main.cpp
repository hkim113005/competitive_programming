#include <iostream>

int main() {
    int n, a[1000], b[1000];

    scanf("%d", &n);

    for (int i = 0; i < n - 1; i++) {
        scanf("%d", &a[i]);
    }

    for (int i = 1; i < a[0]; i++) {
        int x = a[0] - i;
        bool good = true;

        b[0] = i;
        b[1] = x;

        if (i != x) {
            for (int j = 1; j < n - 1; j++) {
                for (int k = 0; k < j + 1; k++) {
                    if (a[j] - x == b[k]) {
                        good = false;
                        break;
                    }
                }

                if (!good) {
                    break;
                }

                x = a[j] - x;

                if (a[j] - x <= 0) {
                    good = false;
                    break;
                }

                b[j + 1] = x;
            }

            if (good) {
                for (int j = 0; j < n; j++) {
                    printf("%d ", b[j]);
                }

                return 0;
            }
        }
    }
}
