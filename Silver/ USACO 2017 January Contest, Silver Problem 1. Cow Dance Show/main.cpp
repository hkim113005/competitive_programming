#include <iostream>
#include <fstream>
#include <queue>

using namespace std;

int N, T, d[10005];

int time_taken(int K) {
    priority_queue<int, vector<int>, greater<int>> stage;
    int time = 0;

    for (int i = 0; i < K; i++) {
        stage.push(d[i]);
    }

    for (int i = K; i < N; i++) {
        int tmp = stage.top();
        tmp += d[i];
        stage.pop();
        stage.push(tmp);

        if (tmp > time) {
            time = tmp;
        }
    }

    return time;
}

int binary_search() {
    int low = 0, high = N;

    while (low < high) {
        int mid = (low + high) / 2;

        if (time_taken(mid) > T) {
            low = mid + 1;
        } else {
            high = mid;
        }
    }

    return low;
}

int main() {
    freopen("cowdance.in", "r", stdin);
    freopen("cowdance.out", "w", stdout);

    cin >> N >> T;

    for (int i = 0; i < N; i++) {
        cin >> d[i];
    }

    cout << binary_search();

    return 0;
}
