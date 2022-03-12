#include <iostream>
#include <vector>
#include <math.h>

#define INF (int)1e9

using namespace std;

int N;
vector<vector<int>> L;
int Q;
vector<pair<vector<int>, int>> H;
vector<pair<vector<int>, int>> G;
vector<pair<vector<int>, int>> A;
int B_H = 0;
int B_G = 0;
vector<vector<int>> mem;

int dfs(int i, int B) {
    if (i == 0 && B == 0) return 1;
    if (i <= 0) return 0;
    if (mem[i][B] != INF) return mem[i][B];

    int res = 0;

    for (int j = 1; j <= A[i].first.size(); j++) {
        if (B & (1 << A[i].first[j])) res += dfs(i - 1, B ^ (1 << A[i].first[j]));
        if (A[i].first[j] == A[i].second) break;
    }

    return mem[i][B] = res;
}

int solve() {
    mem = vector<vector<int>>(H.size(), vector<int>(B_H + 1, INF));
    A = H;
    int a = dfs(H.size() - 1, B_H);
    mem = vector<vector<int>>(G.size(), vector<int>(B_G + 1, INF));
    A = G;
    int b = dfs(G.size() - 1, B_G);
    return a * b;
}

int main() {
    cin >> N;
    L.resize(N + 1);
    for (int i = 1; i <= N; i++) {
        L[i].resize(N + 1);
        for (int j = 1; j <= N; j++) {
            cin >> L[i][j];
        }
    }
    cin >> Q;
    for (int i = 0; i < Q; i++) {
        char b;
        H.clear();
        G.clear();
        H.emplace_back(0, 0);
        G.emplace_back(0, 0);
        B_H = 0;
        B_G = 0;
        for (int j = 1; j <= N; j++) {
            cin >> b;
            if (b == 'H') H.emplace_back(L[j], j), B_H |= (1 << j);
            else G.emplace_back(L[j], j), B_G |= (1 << j);
        }
        cout << solve() << endl;
    }

    return 0;
}
