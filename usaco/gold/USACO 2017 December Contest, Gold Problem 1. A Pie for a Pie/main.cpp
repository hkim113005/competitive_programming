#include <iostream>
#include <set>
#include <queue>
#include <iterator>

using namespace std;

int N, D;
int b[100005][2], e[100005][2];
int dist[100005][2];

struct comp {
    bool operator() (const int&x, const int&y) const;
};

struct compare_b: comp{
    bool operator() (const int&x, const int&y) const {
        return b[x][1] > b[y][1];
    }
};

struct compare_e: comp {
    bool operator() (const int&x, const int&y) const {
        return e[x][0] > e[y][0];
    }
};

multiset<int, compare_b> b_s;
multiset<int, compare_e> e_s;

int main() {
    freopen("piepie.in", "r", stdin);
    freopen("piepie.out", "w", stdout);

    cin >> N >> D;

    for (int i = 0; i < N; i++) {
        cin >> b[i][0] >> b[i][1];

        b_s.insert(i);

        dist[i][0] = dist[i][1] = 1000000000;
    }

    for (int i = 0; i < N; i++) {
        cin >> e[i][0] >> e[i][1];

        e_s.insert(i);
    }

    queue<pair<int, int>> q;

    for (int i = 0; i < N; i++) {
        if (b[i][1] == 0) {
            q.push(make_pair(i, 0));
            dist[i][0] = 0;
            b_s.erase(i);
        }
        if (e[i][0] == 0) {
            q.push(make_pair(i, 1));
            dist[i][1] = 0;
            e_s.erase(i);
        }
    }

    while (!q.empty()) {
        pair<int, int> f = q.front();
        q.pop();

        int(& ref)[100005][2] = f.second == 0 ? e : b;
        int taste = f.second == 0 ? b[f.first][f.second] : e[f.first][f.second];

        ref[N][0] = ref[N][1] = taste;

        if (f.second == 0) e_s.insert(N);
        else b_s.insert(N);

        auto it = f.second == 0 ? e_s.lower_bound(N) : b_s.lower_bound(N);

        multiset<int> to_erase;

        while (!((f.second == 0 && it == e_s.end()) || (f.second == 1 && it == b_s.end())) && ref[*it][f.second] >= taste - D) {
            if (*it == N) {
                it++;
                continue;
            }
            //e_s.end()
            int tmp = *it;
            q.push(make_pair(*it, !f.second));
            dist[*it][!f.second] = dist[f.first][f.second] + 1;
            it++;

            to_erase.insert(tmp);
        }
        for (int x: to_erase) {
            if (f.second == 0) e_s.erase(x);
            else b_s.erase(x);
        }
        if (f.second == 0) e_s.erase(N);
        else b_s.erase(N);
    }

    for (int i = 0; i < N; i++) {
        if (dist[i][0] >= 1000000000) cout << -1 << endl;
        else cout << dist[i][0] + 1 << endl;
    }

    return 0;
}
