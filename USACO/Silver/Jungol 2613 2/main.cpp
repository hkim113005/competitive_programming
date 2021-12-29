#include <iostream>
#include <queue>

using namespace std;

struct node {
    int x, y, cnt;
};

int n, m, ans;
int tomato[1005][1005];
bool explored[1005][1005];
int neighbor_length = 0;
node neighbors[4];
queue<node> q;

node Node(int x, int y, int cnt) {
    node N;
    N.x = x;
    N.y = y;
    N.cnt = cnt;
    return N;
}

void input() {
    cin >> m >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> tomato[i][j];

            if (tomato[i][j] == 1) {
                q.push(Node(i, j, 0));
                explored[i][j] = true;
            }
            else if (tomato[i][j] == -1) {
                explored[i][j] = true;
            }
            else {
                explored[i][j] = false;
            }
        }
    }
}

void get_neighbors(node f) {
    neighbor_length = 0;

    if (f.x - 1 >= 0) {
        if (tomato[f.x - 1][f.y] == 0) {
            neighbors[neighbor_length] = Node(f.x - 1, f.y, f.cnt + 1);

            neighbor_length++;
        }
    }

    if (f.x + 1 < n) {
        if (tomato[f.x + 1][f.y] == 0) {
            neighbors[neighbor_length] = Node(f.x + 1, f.y, f.cnt + 1);

            neighbor_length++;
        }
    }

    if (f.y - 1 >= 0) {
        if (tomato[f.x][f.y - 1] == 0) {
            neighbors[neighbor_length] = Node(f.x, f.y - 1, f.cnt + 1);

            neighbor_length++;
        }
    }

    if (f.y + 1 < m) {
        if (tomato[f.x][f.y + 1] == 0) {
            neighbors[neighbor_length] = Node(f.x, f.y + 1, f.cnt + 1);

            neighbor_length++;
        }
    }
}

void bfs() {
    int max_cnt = 0;

    while(true) {
        /*
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cout << explored[i][j] << " ";
            }

            cout << endl;
        }

        cout << endl << endl;
        */

        if (q.empty()) {
            break;
        }

        node f = q.front();

        q.pop();

        get_neighbors(f);

        if (max_cnt < f.cnt) {
            max_cnt = f.cnt;
        }

        for (int i = 0; i < neighbor_length; i++) {
            if (!explored[neighbors[i].x][neighbors[i].y]) {
                q.push(neighbors[i]);
                explored[neighbors[i].x][neighbors[i].y] = true;
            }
        }
    }

    ans = max_cnt;
}

int main() {
    input();

    bfs();

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!explored[i][j]) {
                cout << -1;

                return 0;
            }
        }
    }

    cout << ans;

    return 0;
}
