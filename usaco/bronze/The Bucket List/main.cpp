#include <iostream>

using namespace std;

int main() {
    int n, time[100][3], max_buckets = 0;

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> time[i][0] >> time[i][1] >> time[i][2];
    }

    for (int i = 1; i <= 1000; i++) {
        int buckets = 0;

        for (int j = 0; j < n; j++) {
            if (time[j][0] <= i && i <= time[j][1]) {
                buckets += time[j][2];
            }
        }

        if (max_buckets < buckets) {
            max_buckets = buckets;
        }
    }

    cout << max_buckets;

    return 0;
}
