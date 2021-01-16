#include <iostream>
#include <stdio.h>

int main() {
    bool N[500], operation;
    for (int i = 0; i < 500; i++) {
        N[i] = false;
    }
    int M, n, S_i, E_i, b;
    scanf("%d %d", &n, &M);
    for (int i = 0; i < M; i++) {
        int cnt = 0;

        scanf("%d %d %d", &b, &S_i, &E_i);
        operation = b;

        if (operation) {
            for (int j = S_i - 1; j < E_i; j++) {
                if (N[j]) {
                    cnt++;
                }
            }
            printf("%d\n", cnt);

            /*for (int j = 0; j < n; j++) {
                printf("%d ", N[j]);
            }
            printf("\n");*/
        }
        else {
            for (int j = S_i - 1; j < E_i; j++) {
                N[j] = !N[j];
            }

            /*for (int j = 0; j < n; j++) {
                printf("%d ", N[j]);
            }
            printf("\n");*/
        }
    }
}