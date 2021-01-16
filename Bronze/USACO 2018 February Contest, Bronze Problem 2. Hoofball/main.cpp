#include <iostream>
#include <stdio.h>
#include <fstream>
#include <algorithm>

using namespace std;

int cows[10000];

bool is_loop(int i1, int i2) {
    int tmp1, tmp2;
    tmp1 = cows[i2] - cows[i1];
    tmp2 = cows[i2 + 1] - cows[i2];
    if (tmp2 < tmp1 && tmp2 >= 0) {
        return false;
    }
    tmp2 = cows[i1] - cows[i1 - 1];
    if (tmp2 < tmp1) {
        return false;
    }
    return true;
}

int main() {
    freopen("hoofball.in","r", stdin);
    freopen("hoofball.out", "w", stdout);

    int n, cnt = 0, min = 10000;
    bool change = false, loop = false;
    scanf("%i", &n);
    for (int i = 0; i < n; i++) {
        scanf("%i", &cows[i]);
    }
    sort(cows, cows + n);
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (cows[n - i] - cows[n - j] < min) {
                min = cows[n - i] - cows[n - j];
            }
        }
    }
    for (int i = 0; i < n - 1; ++i) {
        if (change != loop) {
            cnt++;
            change = loop;
        }
        while (is_loop(i, i + 1)) {
            loop = !change;
            if (is_loop(i + 2, i + 3)) {
                i++;
            }
            i++;
        }
    }
    if (change != loop) {
        cnt++;
        change = loop;
    }
    printf("%d\n", cnt + 1);
    return 0;
}
