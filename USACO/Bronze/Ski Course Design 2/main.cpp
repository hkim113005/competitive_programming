#include <iostream>

int main() {
    int n, hills[1000], min = -1, max = -1;

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &hills[i]);

        if (hills[i] < min || min == -1) {
            min = hills[i];
        }

        if (hills[i] > max || max == -1) {
            max = hills[i];
        }
    }

    int min_cost = -1;

    for (int i = min; i < max - 17; i++) {
        int cost = 0;

        for (int j = 0; j < n; j++) {
            if (hills[j] < i) {
                cost += (i - hills[j]) * (i - hills[j]);
            }
            else if (hills[j] > i + 17) {
                cost += (hills[j] - i - 17) * (hills[j] - i - 17);
            }
        }

        if (cost < min_cost || min_cost == -1) {
            min_cost = cost;
        }

    }

    if (min_cost == -1) {
        printf("0");
    }
    else {
        printf("%d", min_cost);
    }
}
