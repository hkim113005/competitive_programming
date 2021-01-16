#include <iostream>

using namespace std;

int main() {
    int k, n;

    cin >> k >> n;

    for (int i = 0; i < n; i++) {
        int x;

        cin >> x;

        int dist = 0, speed = 1, seconds = 0;

        while (dist < k) {
            dist += speed;
            seconds++;

            if (dist >= k) {
                break;
            }

            if (speed >= x) {
                dist += speed;
                seconds++;

                if (dist >= k) {
                    break;
                }
            }

            speed++;
        }

        cout << seconds << endl;
    }

    return 0;
}
