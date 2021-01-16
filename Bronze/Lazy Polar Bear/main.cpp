#include <iostream>

typedef struct node {
    int ice;
    int pos;
};

node buckets[100000];

int main() {
    int n, k, min = 1000000, max = 0, ice = 0, max_ice = 0;
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &buckets[i].ice, &buckets[i].pos);
        if (buckets[i].pos < min) {
            min = buckets[i].pos;
        }
        if (buckets[i].pos > max) {
            max = buckets[i].pos;
        }
    }
    for (int i = min; i < max; i++) {
        ice = 0;
        if (i - k < 1) {
            continue;
        }
        for (int j = 0; j < n; j++) {
            if (i - k <= buckets[j].pos && buckets[j].pos <= i + k) {
                ice += buckets[j].ice;
            }
        }
        if (ice > max_ice) {
            max_ice = ice;
        }
    }
    printf("%d", max_ice);
}
