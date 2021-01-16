#include <iostream>
#include <stdio.h>
#include <algorithm>

using namespace std;

typedef struct cow {
    int A_i;
    int B_i;
    int id;
};

cow cows[50000];

bool A_i_votes(cow a, cow b) {
    return a.A_i >= b.A_i;
}

bool B_i_votes(cow a, cow b) {
    return a.B_i >= b.B_i;
}

int main() {
    int max[50000], n, k, a = 0;
    scanf("%d %d" , &n, &k);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &cows[i].A_i, &cows[i].B_i);
        cows[i].id = i + 1;
    }
    sort(cows, cows + n, A_i_votes);

    sort(cows, cows + k, B_i_votes);

    printf("%d", cows[0].id);
}
