#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int N, M;
    pair<int, int> a[500000];
    int b[1000];

    cin >> N >> M;

    for (int i = 0; i < M; i++) {
        cin >> a[i].first >> a[i].second;
    }

    sort(a, a + M);

    for (int i = 1; i <= N; i++) {
        b[i] = 1;
    }

    for (int i = 0; i < M; i++) {
        int t;

        t = b[a[i].first] + 1;

        if (t > b[a[i].second]) {
            b[a[i].second] = t;
        }
    }

    for (int i = 1; i <= N; i++) {
        cout << b[i] << " ";
    }

    cout << endl;

    return 0;
}
