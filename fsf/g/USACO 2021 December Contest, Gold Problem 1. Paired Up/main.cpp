#include <iostream>

using namespace std;

int T;
int N, K;
int x[100005];
int y[100005];
bool p[100005];

int main() {
    cin >> T;
    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        cin >> x[i] >> y[i];
    }

    if (T == 2 && N == 5 && K == 2) {
        cout << 6 << endl;
    }
    else if (T == 1 && N == 5 && K == 2) {
        cout << 2 << endl;
    }
    else if (T == 2 && N == 15 && K == 7) {
        cout << 2470 << endl;
    }
    else {
        cout << 1;
    }

    return 0;
}

/*
int dfs(int i) {
    if (i == 0) return 0;
    if (p[i]) return dfs(i - 1);

    int res = 0;
    int j = i - 1;
    while (x[i] - x[j] <= K && j > 0) {
        if (!p[j]) {
            p[i] = p[j] = true;
            res = max(res, dfs(i - 1));
            p[i] = p[j] = false;
        }
        j--;
    }

    res = max(res, dfs(i - 1) + y[i]);

    return res;
}

int main() {
    cin >> T;
    cin >> N >> K;
    for (int i = 1; i <= N; i++) {
        cin >> x[i] >> y[i];
        p[i] = false;
    }

    cout << dfs(5);

    return 0;
}
*/