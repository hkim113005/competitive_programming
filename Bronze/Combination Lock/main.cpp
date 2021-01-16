#include <iostream>

int m, combinations[100000][3];

void process(int a, int b, int c) {
    for (int i = 0; i < m; i++) {
        if (combinations[i][0] == a && combinations[i][1] == b && combinations[i][2] == c) {
            return;
        }
    }
    combinations[m][0] = a;
    combinations[m][1] = b;
    combinations[m][2] = c;
    m++;
}

int main() {
    int n, farmer[3], master[3];
    scanf("%d", &n);
    scanf("%d %d %d", &farmer[0], &farmer[1], &farmer[2]);
    scanf("%d %d %d", &master[0], &master[1], &master[2]);

    for (int i = farmer[0] - 2; i <= farmer[0] + 2; i++) {
        for (int j = farmer[1] - 2; j <= farmer[1] + 2; j++) {
            for (int k = farmer[2] - 2; k <= farmer[2] + 2; k++) {
                int a = i, b = j, c = k;

                while (a < 1) {
                    a += n;
                }
                while (a > n) {
                    a -= n;
                }

                while (b < 1) {
                    b += n;
                }
                while (b > n) {
                    b -= n;
                }

                while (c < 1) {
                    c += n;
                }
                while (c > n) {
                    c -= n;
                }

                process(a, b, c);
            }
        }
    }

    for (int i = master[0] - 2; i <= master[0] + 2; i++) {
        for (int j = master[1] - 2; j <= master[1] + 2; j++) {
            for (int k = master[2] - 2; k <= master[2] + 2; k++) {
                int a = i, b = j, c = k;

                while (a < 1) {
                    a += n;
                }
                while (a > n) {
                    a -= n;
                }

                while (b < 1) {
                    b += n;
                }
                while (b > n) {
                    b -= n;
                }

                while (c < 1) {
                    c += n;
                }
                while (c > n) {
                    c -= n;
                }

                process(a, b, c);
            }
        }
    }

    printf("%d", m);
}
