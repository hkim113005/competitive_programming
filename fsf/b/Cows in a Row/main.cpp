#include <iostream>

using namespace std;

int main() {
    int n, cows[1001], breeds[1001], breed_cnt = 0;

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> cows[i];

        bool exists = false;

        for (int j = 0; j < breed_cnt; j++) {
            if (cows[i] == breeds[j]) {
                exists = true;
                break;
            }
        }

        if (!exists) {
            breeds[breed_cnt] = cows[i];
            breed_cnt++;
        }
    }

    int cnt_max = -1;

    for (int x = 0; x < breed_cnt; x++) {
        int i = breeds[x];

        int current_breed = -1;
        int cnt = 1;

        for (int j = 0; j < n; j++) {
            if (cows[j] != current_breed && cows[j] != i) {
                if (cnt_max < cnt) {
                    cnt_max = cnt;
                }

                current_breed = cows[j];
                cnt = 1;
            }
            else if (cows[j] == current_breed && cows[j] != i) {
                cnt++;
            }
        }

        if (cnt_max < cnt) {
            cnt_max = cnt;
        }
    }

    printf("%d", cnt_max);

    return 0;
}
