#include <iostream>
#include <algorithm>

using namespace std;

int N, K;
int ranges[100000];
int ranges_len = 0;
int differences[100000];
int ans = 0;

int main() {
    cin >> N >> K;

    for (int i = 0; i < N; i++) {
        int t;

        cin >> t;

        bool exists = false;

        for (int j = 0; j < ranges_len; j++) {
            if (ranges[j] == t / 12 + 1) {
                exists = true;
                break;
            }
        }

        if (!exists) {
            ranges[ranges_len] = t / 12 + 1;
            ranges_len++;
        }
    }

    sort(ranges, ranges + ranges_len);

    for (int i = 0; i < ranges_len - 1; i++) {
        differences[i] = ranges[i + 1] - ranges[i] - 1;
    }

    differences[ranges_len - 1] = ranges[0] - 1;

    sort(differences, differences + ranges_len, greater<int>());

    ans = ranges[ranges_len - 1] * 12;

    K--;

    for (int i = 0; i < ranges_len - 1; i++) {
        if (K > 0) {
            ans -= differences[i] * 12;

            K--;
        }
    }

    cout << ans;

    return 0;
}
