#include <iostream>

using namespace std;

int main() {
    int R, C, K;

    cin >> C >> R >> K;

    int d = 0;
    int up = R;
    int right = C - 1;
    int down = R - 1;
    int left = C - 2;
    int total = 0;
    int x = 1;
    int y = 0;

    if (K <= R * C) {
        while (true) {
            switch (d) {
                case 0:
                    for (int j = 0; j < up; j++) {
                        y++;

                        total++;

                        if (total == K) {
                            cout << x << " " << y;

                            exit(0);
                        }
                    }

                    up -= 2;

                    d = 1;
                case 1:
                    for (int j = 0; j < right; j++) {
                        x++;

                        total++;

                        if (total == K) {
                            cout << x << " " << y;

                            exit(0);
                        }
                    }

                    right -= 2;

                    d = 2;
                case 2:
                    for (int j = 0; j < down; j++) {
                        y--;

                        total++;

                        if (total == K) {
                            cout << x << " " << y;

                            exit(0);
                        }
                    }

                    down -= 2;

                    d = 3;
                case 3:
                    for (int j = 0; j < left; j++) {
                        x--;

                        total++;

                        if (total == K) {
                            cout << x << " " << y;

                            exit(0);
                        }
                    }

                    left -= 2;

                    d = 0;
            }
        }
    }

    cout << 0;

    return 0;
}
