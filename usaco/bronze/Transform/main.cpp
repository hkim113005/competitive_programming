#include <iostream>
#include <string.h>

typedef struct node {
    char type[100];
    int cnt = 0;
} node;

struct node a[100];
int size = 0;

int main() {
    int n;

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        int m;

        scanf("%d", &m);

        for (int j = 0; j < m; j++) {
            char tmp[100], gbg[100];

            scanf("%s %s", gbg, tmp);

            bool new_type = true;

            for (int k = 0; k < size + 1; k++) {
                if (strcmp(tmp, a[k].type) == 0) {
                    a[k].cnt++;
                    new_type = false;
                }
            }

            if (new_type) {
                strcpy(a[size].type, tmp);
                a[size].cnt++;
                size++;
            }
        }

        int ans = 1;

        for (int j = 0; j < size; j++) {
            ans *= a[j].cnt + 1;
            strcpy(a[j].type, "");
            a[j].cnt = 0;
        }

        ans--;

        printf("%d\n", ans);

        size = 0;
    }
}
