#include <iostream>
#include <stdio.h>
#include <math.h>

int main() {
    int n, pos[500][2], a, b;
    double max = 0;

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d %d", &pos[i][0], &pos[i][1]);
    }

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int x_dif = pos[i][0] - pos[j][0];
            int y_dif = pos[i][1] - pos[j][1];

            double dist = sqrt((double)(x_dif * x_dif + y_dif * y_dif));

            if (dist > max) {
                max = dist;
                a = i;
                b = j;
            }
        }
    }

    printf("%d %d", a + 1, b + 1);

    return 0;
}
