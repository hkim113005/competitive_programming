#include <iostream>

using namespace std;

int N, K;
int pairs[10000][2];
int order[10000];
int cnt[10000];
bool check[10000][10000];

int main() {
    cin >> N >> K;

    for (int i = 0; i < K; i++) {
        cin >> pairs[i][0] >> pairs[i][1];
    }

    for (int i = 1; i <= N; i++) {
        order[i] = i;
        check[i][i] = true;
        cnt[i] = 1;
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < K; j++) {
            int tmp = order[pairs[j][0]];
            order[pairs[j][0]] = order[pairs[j][1]];
            order[pairs[j][1]] = tmp;

            if (!check[order[pairs[j][0]]][pairs[j][0]]) {
                cnt[order[pairs[j][0]]]++;
                check[order[pairs[j][0]]][pairs[j][0]] = true;
            }

            if (!check[order[pairs[j][1]]][pairs[j][1]]) {
                cnt[order[pairs[j][1]]]++;
                check[order[pairs[j][1]]][pairs[j][1]] = true;
            }
        }
    }

    for (int i = 1; i <= N; i++) {
        cout << cnt[i] << endl;
    }

    return 0;
}
