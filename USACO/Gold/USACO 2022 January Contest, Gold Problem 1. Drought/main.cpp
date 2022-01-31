#include <iostream>

using namespace std;

int N;
int H[105];
int a[105][1005];

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> H[i];
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < H[i]; j++) {
            a[i][j + 1];
            a[i + 1][j + 1];
        }
    }

    return 0;
}
