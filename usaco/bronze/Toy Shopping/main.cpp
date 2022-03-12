#include <iostream>
#include <algorithm>

using namespace std;

static int compare(const void * pa, const void * pb) {
    double *q1 = (double *)pa;
    double *q2 = (double *)pb;
    if ( *q1 > *q2 ) { return -1; }
    else if ( *q1 < *q2 ) { return 1; }
    else { return 0; }
}

int main() {
    int n, toys[25000][2];
    double hfm[25000][2];

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d %d", &toys[i][0], &toys[i][1]);

        hfm[i][0] = (double)toys[i][0] / (double)toys[i][1];
        hfm[i][1] = i;
    }

    qsort(hfm, n, sizeof(double) * 2, compare);

    printf("%d\n", toys[(int)hfm[0][1]][1] + toys[(int)hfm[1][1]][1] + toys[(int)hfm[2][1]][1]);
    printf("%d\n%d\n%d\n", (int)hfm[0][1] + 1, (int)hfm[1][1] + 1, (int)hfm[2][1] + 1);

    return 0;
}
