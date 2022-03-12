#include <iostream>

using namespace std;

int N, K;
int pairs[100000][2];
bool check[100000];

int dance(int x) {
    int next = x;
    check[x] = true;

    while (true) {

        for (int i = 0; i < K; i++) {
            if (pairs[i][0] == next) {
                next = pairs[i][1];
            }
            else if (pairs[i][1] == next) {
                next = pairs[i][0];
            }

            check[next] = true;
        }

        if (next == x) {
            int cnt = 0;

            for (int i = 1; i <= N; i++) {
                if (check[i]) {
                    cnt++;
                }
            }

            return cnt;
        }
    }
}

int main() {
    cin >> N >> K;

    for (int i = 0; i < K; i++) {
        cin >> pairs[i][0] >> pairs[i][1];
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 0; j < N; j++) {
            check[j] = false;
        }

        cout << dance(i) << endl;
    }

    return 0;
}
