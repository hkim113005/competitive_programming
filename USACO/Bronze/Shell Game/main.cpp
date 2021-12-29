#include <iostream>

int main() {
    int n, one = 0, two = 0, three = 0, shells[3] = { 1, 2, 3 };

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        int a, b, g;

        scanf("%d %d %d", &a, &b, &g);

        a--;
        b--;
        g--;

        int tmp = shells[a];
        shells[a] = shells[b];
        shells[b] = tmp;

        if (shells[g] == 1) {
            one++;
        }
        else if (shells[g] == 2) {
            two++;
        }
        else if (shells[g] == 3) {
            three++;
        }
    }

    if (one >= two && one >= three) {
        printf("%d", one);
    }
    else if (two >= one && two >= three) {
        printf("%d", two);
    }
    else if (three >= one && three >= two) {
        printf("%d", three);
    }
}
