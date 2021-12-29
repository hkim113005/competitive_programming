#include <iostream>
#include <string.h>

typedef struct node {
    char t[100][20];
    int len;
} node;

node animals[100];

int main() {
    int n, max = 0;

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        char tmp[20];
        int m;

        scanf("%s", tmp);
        scanf("%d", &m);

        animals[i].len = m;

        for (int j = 0; j < m; j++) {
            scanf("%s", animals[i].t[j]);
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int cnt = 0;

            for (int k = 0; k < animals[i].len; k++) {
                for (int l = 0; l < animals[j].len; l++) {
                    if (strcmp(animals[i].t[k], animals[j].t[l]) == 0) {
                        cnt++;
                    }
                }
            }

            if (cnt > max) {
                max = cnt;
            }
        }
    }

    printf("%d", max + 1);
}
