#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

struct node {
    int x, y, cnt;
};

int n, m, k;
int bus[5005][4];
int s_x, s_y;
int t_x, t_y;
int possible_points_cnt[5005] = { 0 };
int possible_points[5005][10000][2];

node make_node(int x, int y, int cnt) {
    node N;
    N.x = x;
    N.y = y;
    N.cnt = cnt;
    return N;
}

void input() {
    cin >> m >> n;

    cin >> k;

    for (int i = 0; i < k; i++) {
        int t;

        cin >> t;

        cin >> bus[i][0] >> bus[i][1] >> bus[i][2] >> bus[i][3];

        bus[i][0]--;
        bus[i][1]--;
        bus[i][2]--;
        bus[i][3]--;
    }

    cin >> s_x >> s_y;
    cin >> t_x >> t_y;

    s_x--;
    s_y--;
    t_x--;
    t_y--;
}

void find_possible_points() {
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < k; j++) {
            if (bus[i][0] == bus[i][2]) {
                if (bus[i][0] == t_x && min(bus[i][1], bus[i][3]) <= t_y && t_y <= max(bus[i][1], bus[i][3])) {
                    possible_points[i][possible_points_cnt[i]][0] = t_x;
                    possible_points[i][possible_points_cnt[i]][1] = t_y;

                    possible_points_cnt[i]++;
                }

                if (bus[j][1] == bus[j][3]) {
                    if (min(bus[j][0], bus[j][2]) <= bus[i][0] && bus[i][0] <= max(bus[j][0], bus[j][2]) && min(bus[i][1], bus[i][3]) <= bus[j][1] && bus[j][1] <= max(bus[i][1], bus[i][3])) {
                        possible_points[i][possible_points_cnt[i]][0] = bus[i][0];
                        possible_points[i][possible_points_cnt[i]][1] = bus[j][1];

                        possible_points_cnt[i]++;
                    }
                }
                else if (bus[j][0] == bus[j][2]) {
                    if ()
                }
            }
            else if (bus[i][1] == bus[i][3]) {
                if (bus[i][1] == t_y && min(bus[i][0], bus[i][2]) <= t_x && t_x <= max(bus[i][0], bus[i][2])) {
                    possible_points[i][possible_points_cnt[i]][0] = t_x;
                    possible_points[i][possible_points_cnt[i]][1] = t_y;

                    possible_points_cnt[i]++;
                }

                if (bus[j][0] == bus[j][2]) {
                    if (min(bus[i][0], bus[i][2]) <= bus[j][0] && bus[j][0] <= max(bus[i][0], bus[i][2]) && min(bus[j][1], bus[j][3]) <= bus[i][1] && bus[i][1] <= max(bus[j][1], bus[j][3])) {
                        possible_points[i][possible_points_cnt[i]][0] = bus[j][0];
                        possible_points[i][possible_points_cnt[i]][1] = bus[i][1];

                        possible_points_cnt[i]++;
                    }
                }
            }
        }
    }
}

void bfs() {
    queue<node> q;

    q.push(make_node(s_x, s_y, 0));

    bool explored[5005];

    for (int i = 0; i < k; i++) {
        explored[i] = false;
    }

    while (true) {
        if (q.empty()) {
            cout << -1;
            return;
        }

        node f = q.front();

        q.pop();

        if (f.x == t_x && f.y == t_y) {
            cout << f.cnt;
            return;
        }

        for (int i = 0; i < k; i++) {
            if (!explored[i]) {
                if (bus[i][0] == bus[i][2] && bus[i][0] == f.x && min(bus[i][1], bus[i][3]) <= f.y && f.y <= max(bus[i][1], bus[i][3])) {
                    for (int j = 0; j < possible_points_cnt[i]; j++) {
                        q.push(make_node(possible_points[i][j][0], possible_points[i][j][1], f.cnt + 1));
                    }

                    explored[i] = true;
                }
                else if (bus[i][1] == bus[i][3] && bus[i][1] == f.y && min(bus[i][0], bus[i][2]) <= f.x && f.x <= max(bus[i][0], bus[i][2])) {
                    for (int j = 0; j < possible_points_cnt[i]; j++) {
                        q.push(make_node(possible_points[i][j][0], possible_points[i][j][1], f.cnt + 1));
                    }

                    explored[i] = true;
                }
            }
        }
    }
}

int main() {
    input();

    find_possible_points();

    bfs();

    return 0;
}
