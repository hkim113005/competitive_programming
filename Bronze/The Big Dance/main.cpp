#include <iostream>

int sum;

void process(int a[2200], int n) {
    if (n == 2) {
        sum += a[0] * a[1];
        return;
    }
    else if (n == 1) {
        return;
    }
    else if (n % 2 == 0) {
        int tmp1[2200];
        for (int i = 0; i < n / 2; i++) {
            tmp1[i] = a[i];
        }
        process(tmp1, n / 2);

        int tmp2[2200];
        for (int i = 0; i < n / 2; i++) {
            tmp2[i] = a[n / 2 + i];
        }
        process(tmp2, n / 2);
    }
    else {
        int tmp1[2200];
        for (int i = 0; i < n / 2 + 1; i++) {
            tmp1[i] = a[i];
        }
        process(tmp1, n / 2 + 1);

        int tmp2[2200];
        for (int i = 0; i < n / 2; i++) {
            tmp2[i] = a[n / 2 + 1 + i];
        }
        process(tmp2, n / 2);
    }
}

int main() {
    int a[2200], n;

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        a[i] = i + 1;
    }

    process(a, n);

    printf("%d", sum);

    return 0;
}
