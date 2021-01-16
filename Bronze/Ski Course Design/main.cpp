#include <iostream>
#include <algorithm>

using namespace std;

int n, hills[1000];

int next_min(int x) {
    for (int i = 0; i < n; i++) {
        if (hills[i] > x) {
            return hills[i];
        }
    }
}

int next_max(int x) {
    for (int i = n - 1; i >= 0; i--) {
        if (hills[i] < x) {
            return hills[i];
        }
    }
}

int main() {
    int min_init = -1, max_init = 0;

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &hills[i]);
        if (hills[i] < min_init || min_init == -1) {
            min_init = hills[i];
        }
        if (hills[i] > max_init) {
            max_init = hills[i];
        }
    }

    sort(hills, hills + n);

    int min = min_init, max = max_init, min_multi = 1, max_multi = 1;

    while (max - min > 17) {
        int new_min = next_min(min);
        int new_max = next_max(max);

        int min_value = 1000000000, max_value = 1000000000;

        if (max - new_min < 17 || new_max - min < 17) {
            if (max - new_min < 17) {
                min_value = ((max - min) - 17) * min_multi;
            }
            if (new_max - min < 17) {
                max_value = ((max - min) - 17) * max_multi;
            }

            if (min_value < max_value) {
                min = max - 17;
                min_multi++;
            } else {
                max = min + 17;
                max_multi++;
            }
        }
        else {
            if (max - new_min >= 17) {
                min_value = (new_min - min) * min_multi;
            }
            if (new_max - min >= 17) {
                max_value = (max - new_max) * max_multi;
            }

            if (min_value < max_value) {
                min = new_min;
                min_multi++;
            } else {
                max = new_max;
                max_multi++;
            }
        }
    }

    int total_cost = 0;

    for (int i = 0; i < n; i++) {
        if (hills[i] < min) {
            total_cost += (min - hills[i]) * (min - hills[i]);
        }
        if (hills[i] > max) {
            total_cost += (hills[i] - max) * (hills[i] - max);
        }
    }

    printf("%d %d %d", min, max, total_cost);
}