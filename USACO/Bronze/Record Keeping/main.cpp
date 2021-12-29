#include <iostream>
#include <algorithm>
#include <string.h>

using namespace std;

int n, m = 0, cnt[1000];
char words[1000][3][100], triples[1000][3][100];

void in_triples(char a[100], char b[100], char c[100]) {
    for (int i = 0; i < m; i++) {
        if (strcmp(triples[i][0], a) == 0 && strcmp(triples[i][1], b) == 0 && strcmp(triples[i][2], c) == 0) {
            cnt[i]++;
            return;
        }
    }
    strcpy(triples[m][0], a);
    strcpy(triples[m][1], b);
    strcpy(triples[m][2], c);
    cnt[m]++;
    m++;
    return;
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s %s %s", words[i][0], words[i][1], words[i][2]);

        for (int j = 0; j < 3; j++) {
            for (int k = j + 1; k < 3; k++) {
                if (strcmp(words[i][0], words[i][1]) >= 1) {
                    char tmp[100];
                    strcpy(tmp, words[i][0]);
                    strcpy(words[i][0], words[i][1]);
                    strcpy(words[i][1], tmp);
                }
                if (strcmp(words[i][1], words[i][2]) >= 1) {
                    char tmp[100];
                    strcpy(tmp, words[i][1]);
                    strcpy(words[i][1], words[i][2]);
                    strcpy(words[i][2], tmp);
                }
            }
        }

        in_triples(words[i][0], words[i][1], words[i][2]);
    }

    int maximum = 0;
    for (int i = 0; i < m; i++) {
        if (cnt[i] > maximum) {
            maximum = cnt[i];
        }
    }

    printf("%d", maximum);
}
