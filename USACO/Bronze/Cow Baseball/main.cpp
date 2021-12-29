#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n, cows[10000];
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &cows[i]);
    }
    sort(cows, cows + n);

    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            for (int k = j + 1; k < n; k++) {
                int XY = cows[j] - cows[i];
                int YZ = cows[k] - cows[j];
                if (XY <= YZ && YZ <= 2 * XY) {
                    cnt++;
                }
            }
        }
    }

    printf("%d", cnt);
}
