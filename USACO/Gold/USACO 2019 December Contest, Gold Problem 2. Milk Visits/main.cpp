#include <iostream>
#include <stack>
#include <vector>
#include <set>
#include <iterator>
#include <math.h>

using namespace std;

typedef long long ll;

int N, M;
int T[100100];
int A[100100], B[100100], C[100100];
vector<int> e[100100];
stack<int, vector<int>> c[100100];
vector<pair<int, int>> check[100100];
vector<int> res[100100];
int par[105][100100];
int dep[100100];

void dfs(int x, int d, int p) {
    c[T[x]].push(x);
    dep[x] = d;

    for (auto it : check[x]) {
        if (!c[it.first].empty()) {
            res[it.second].push_back(c[it.first].top());
        }
        else {
            res[it.second].push_back(-1);
        }
    }

    for (int i = 0; i < e[x].size(); i++) {
        if (p != e[x][i]) {
            par[0][e[x][i]] = x;
            dfs(e[x][i], d + 1, x);
        }
    }

    c[T[x]].pop();
}

bool bt(int x, int y, int z) {
    if (x == z || y == z) return true;

    int idx = 0;
    int dif = dep[x] - dep[z] - 1;

    while (dif > 0) {
        if (dif % 2 == 1) {
            x = par[idx][x];
        }
        idx++;
        dif /= 2;
    }

    idx = 0;
    dif = dep[y] - dep[z] - 1;

    while (dif > 0) {
        if (dif % 2 == 1) {
            y = par[idx][y];
        }
        idx++;
        dif /= 2;
    }

    return x != y;
}

int main() {
    freopen("milkvisits.in", "r", stdin);
    freopen("milkvisits.out", "w", stdout);
    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        cin >> T[i];
    }
    for (int i = 0; i < N - 1; i++) {
        int X, Y;
        cin >> X >> Y;
        e[X].emplace_back(Y);
        e[Y].emplace_back(X);
    }
    for (int i = 0; i < M; i++) {
        cin >> A[i] >> B[i] >> C[i];
        check[A[i]].emplace_back(make_pair(C[i], i));
        check[B[i]].emplace_back(make_pair(C[i], i));
    }

    dfs(1, 0, -1);

    for (int i = 1; i < 100; i++) {
        for (int j = 1; j <= N; j++) {
            par[i][j] = par[i - 1][par[i - 1][j]];
        }
    }

    for (int i = 0; i < M; i++) {
        //cout << res[A[i]][C[i]] << " " << res[B[i]][C[i]] << endl;
        if (res[i][0] == -1 && res[i][1] == -1) {
            cout << false;
        }
        else if (res[i][0] != res[i][1]) {
            cout << true;
        }
        else {
            cout << bt(A[i], B[i], res[i][0]);
        }
    }
    cout << endl;

    return 0;
}
