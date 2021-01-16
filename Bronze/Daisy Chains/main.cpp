#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    int n, flowers[105], cnt = 0;

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> flowers[i];
    }

    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            int sum = 0;

            for (int k = i; k <= j; k++) {
                sum += flowers[k];
            }

            double avg = (double)sum / (j - i + 1);
            double tmp;
            if (modf(avg, &tmp) == 0) {
                for (int k = i; k <= j; k++) {
                    if (flowers[k] == avg) {
                        cnt++;
                        break;
                    }
                }
            }
        }
    }

    cout << cnt;

    return 0;
}
