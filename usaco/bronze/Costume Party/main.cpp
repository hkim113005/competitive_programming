#include <iostream>
#include <stdio.h>

int main() {
    int n, s, cows[20000], cnt = 0;
    scanf("%d %d", &n, &s);
    for (int i = 0; i < n; i++) {
        scanf("%d", &cows[i]);
    }
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (cows[i] + cows[j] <= s) {
                cnt++;
            }
        }
    }
    printf("%d", cnt);
}
