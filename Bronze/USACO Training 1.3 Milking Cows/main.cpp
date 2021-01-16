/*
ID: Hyungjae Kim [hyungja1]
LANG: C++
TASK: milk2
*/

#include <iostream>
#include <stdio.h>
#include <fstream>
#include <algorithm>

using namespace std;

int main() {
    freopen("milk2.in", "r", stdin);
    freopen("milk2.out", "w", stdout);

    int N, a[100][2], min = 1000000, max = 0, b[10000] = { 0 }, n = 0, m = 0, cnt = 0, mode = 0;
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d %d", &a[i][0], &a[i][1]);
        if (a[i][0] < min) {
            min = a[i][0];
        }
        if (a[i][1] > max) {
            max = a[i][1];
        }
        for (int j = a[i][0]; j < a[i][1]; j++) {
            b[j]++;
        }
    }
    for (int i = min; i < max; i++) {
        if (b[i] != 0) {
            if (mode == 0) {
                if (cnt > n) {
                    n = cnt;
                }
                cnt = 0;
            }
            cnt++;
            mode = 1;
        } else {
            if (mode == 1) {
                if (cnt > m) {
                    n = cnt;
                }
                cnt = 0;
            }
            cnt++;
            mode = 0;
        }
    }
    printf("%d %d\n", n, m);
}