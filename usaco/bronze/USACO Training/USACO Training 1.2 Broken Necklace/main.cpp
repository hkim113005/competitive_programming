/*
ID: Hyungjae Kim (hyungja1)
LANG: C++
TASK: beads
*/
#include <iostream>
#include <string>
#include <cstring>

int process(int N, char ncklc[702]) {
    int red = 0, blue = 0, cnt = 0, max = 0;
    char mode = 'w';
    for (int i = 0; i < N; i++) {
        int j = i;
        while (true) {
            if (j + 1 > N) {
                j = -1;
            } else if (cnt > N) {
                cnt = N;
                break;
            } else if (ncklc[j] == 'w') {
                cnt++;
            } else if (ncklc[j] == 'r') {
                if (mode == 'w') {
                    mode = 'r';
                    cnt++;
                } else if (mode == 'b') {
                    break;
                } else {
                    cnt++;
                }
            } else if (ncklc[j] == 'b') {
                if (mode == 'w') {
                    mode = 'b';
                    cnt++;
                } else if (mode == 'r') {
                    break;
                } else {
                    cnt++;
                }
            }
            j++;
        }
        j = i - 1;
        mode = 'w';
        while (true) {
            if (j - 1 < -1) {
                j = N;
            } else if (cnt > N) {
                cnt = N;
                break;
            } else if (ncklc[j] == 'w') {
                cnt++;
            } else if (ncklc[j] == 'r') {
                if (mode == 'w') {
                    mode = 'r';
                    cnt++;
                } else if (mode == 'b') {
                    break;
                } else {
                    cnt++;
                }
            } else if (ncklc[j] == 'b') {
                if (mode == 'w') {
                    mode = 'b';
                    cnt++;
                } else if (mode == 'r') {
                    break;
                } else {
                    cnt++;
                }
            }
            j--;
        }
        if (max < cnt) {
            max = cnt;
        }
        cnt = 0;
        mode = 'w';
    }
    return max;
}

int main() {
    freopen("beads.in", "r", stdin);
    freopen("beads.out", "w", stdout);

    int N = 0;
    char ncklc[702];
    scanf("%d", &N);
    scanf("%s", ncklc);
    printf("%d\n", process(N, ncklc));
}
