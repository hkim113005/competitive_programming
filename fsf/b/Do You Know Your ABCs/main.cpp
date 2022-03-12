#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int number[7];

    for (int i = 0; i < 7; i++) {
        cin >> number[i];
    }

    sort(number, number + 7);

    for (int i = 0; i < 7; i++) {
        for (int j = i + 1; j < 7; j++) {
            for (int k = j + 1; k < 7; k++) {
                bool exists[7];

                for (int l = 0; l < 7; l++) {
                    exists[l] = true;
                }

                exists[i] = false;
                exists[j] = false;
                exists[k] = false;

                int ab = number[i] + number[j];
                int bc = number[j] + number[k];
                int ac = number[i] + number[k];
                int abc = number[i] + number[j] + number[k];

                bool w, x, y, z;
                w = x = y = z = false;

                for (int l = 0; l < 7; l++) {
                    if (number[l] == ab && exists[l] && !w) {
                        w = true;
                        exists[l] = false;
                    }
                    if (number[l] == bc && exists[l] && !x) {
                        x = true;
                        exists[l] = false;
                    }
                    if (number[l] == ac && exists[l] && !y) {
                        y = true;
                        exists[l] = true;
                    }
                    if (number[l] == abc && exists[l] && !z) {
                        z = true;
                        exists[l] = true;
                    }
                }

                if (w && x && y && z) {
                    cout << number[i] << ' ' << number[j] << ' ' << number[k] << endl;
                    return 0;
                }
            }
        }
    }

    return 0;
}
