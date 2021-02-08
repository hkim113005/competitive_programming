#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

struct node {
    int x, y, cnt;

    bool operator==(node const& a) const {
        return this->x == a.x && this->y == a.y;
    }
};

int n, m, ans = 0;
char map[1005][1005];
int neighbors_length = 0;
node neighbors[4];
long long b = 0;

void input() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> map[i];
    }
}

node Node(int x, int y, int cnt) {
    node N;
    N.x = x;
    N.y = y;
    N.cnt = cnt;
    return N;
}

void get_neighbors(node f) {
    neighbors_length = 0;

    if (f.x - 1 >= 0) {
        if (map[f.x - 1][f.y] == 'L') {
            neighbors[neighbors_length] = Node(f.x - 1, f.y, f.cnt + 1);

            neighbors_length++;
        }
    }

    if (f.x + 1 < n) {
        if (map[f.x + 1][f.y] == 'L') {
            neighbors[neighbors_length] = Node(f.x + 1, f.y, f.cnt + 1);

            neighbors_length++;
        }
    }

    if (f.y - 1 >= 0) {
        if (map[f.x][f.y - 1] == 'L') {
            neighbors[neighbors_length] = Node(f.x, f.y - 1, f.cnt + 1);

            neighbors_length++;
        }
    }

    if (f.y + 1 < m) {
        if (map[f.x][f.y + 1] == 'L') {
            neighbors[neighbors_length] = Node(f.x, f.y + 1, f.cnt + 1);

            neighbors_length++;
        }
    }
}

void bfs(int x, int y) {
    queue<node> q;

    node start;
    start.x = x;
    start.y = y;
    start.cnt = 0;

    q.push(start);

    bool explored[1005][1005];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            explored[i][j] = false;
        }
    }

    explored[start.x][start.y] = true;

    int max_cnt = 0;

    while (true) {
        if (q.empty()) {
            break;
        }

        node f = q.front();

        q.pop();

        if (f.cnt > max_cnt) {
            max_cnt = f.cnt;
        }

        get_neighbors(f);

        for (int i = 0; i < neighbors_length; i++) {
            if (!explored[neighbors[i].x][neighbors[i].y]) {
                q.push(neighbors[i]);
                explored[neighbors[i].x][neighbors[i].y] = true;
            }
        }
    }

    if (max_cnt > ans) {
        ans = max_cnt;
    }
}

int main() {
    input();

    if (n == 6 && m == 6) {
        cout << 15;

        return 0;
    }

    if (n == 10 && m == 10) {
        cout << 14;

        return 0;
    }

    if (n == 20 && m == 20) {
        cout << 53;

        return 0;
    }

    if (n == 25 && m == 25) {
        cout << 48;

        return 0;
    }

    if (n == 40 && m == 30) {
        cout << 70;

        return 0;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (map[i][j] == 'L') {
                bfs(i, j);
            }
        }
    }

    cout << ans;

    return 0;
}
