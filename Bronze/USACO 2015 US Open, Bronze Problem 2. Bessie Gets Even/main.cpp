#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <stdlib.h>
#include <ctype.h>

typedef struct node {
    int num;
    struct node *next;
} node;

node *numbers[9];
int cnt[9];

int hash(char key) {
    if (key == 'B') {
        return 0;
    }
    else if (key == 'E') {
        return 1;
    }
    else if (key == 'S') {
        return 2;
    }
    else if (key == 'I') {
        return 3;
    }
    else if (key == 'G') {
        return 4;
    }
    else if (key == 'O') {
        return 5;
    }
    else if (key == 'M') {
        return 6;
    }
}

int main() {
    int n, tmp;
    char key;
    scanf("%i", &n);
    for (int i = 0; i < n; i++) {
        scanf("%c", &key);
        if (key == 10) {
            scanf("%c", &key);
        }
        scanf("%i", &tmp);
        node *N = (node*)calloc(1, sizeof(node));
        int index = hash(key);
        if (n == NULL) {
            return 1;
        }
        N -> num = tmp;
        if (numbers[index] == NULL) {
            numbers[index] = N;
        }
        else {
            N->next = numbers[index];
            numbers[index] = N;
        }
        cnt[index]++;
    }

    for (int i = 0; i < cnt[0]; i++) {
        for (int j = 0; j < cnt[1]; j++) {
            for (int k = 0; k < cnt[2]; k++) {
                for (int l = 0; l < cnt[3]; l++) {
                    for (int m = 0; m < cnt[4]; m++) {
                        for (int n = 0; n < cnt[5]; n++) {
                            for (int o = 0; o < cnt[6]; o++) {
                                if (())
                            }
                        }
                    }
                }
            }
        }
    }
    printf("%i", numbers[0] -> next);
    return 0;
}
