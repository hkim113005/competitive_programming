#include <iostream>
#include <queue>

using namespace std;

struct node {
    int x, y, d, cnt;
};

int n, m;
int map[105][105];
node start;
node target;
int neighbors_length = 0;
node neighbors[5];

void input() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> map[i][j];
        }
    }

    cin >> start.x >> start.y >> start.d;
    cin >> target.x >> target.y >> target.d;

    start.x--;
    start.y--;
    start.cnt = 0;

    target.x--;
    target.y--;
}

node Node(int x, int y, int d, int cnt) {
    node N;
    N.x = x;
    N.y = y;
    N.d = d;
    N.cnt = cnt;
    return N;
}

void get_possible_actions(node f) {
    int x = f.x;
    int y = f.y;
    int d = f.d;
    int cnt = f.cnt;

    neighbors_length = 0;

    if (d == 1) {
        if (y + 1 < m && map[x][y + 1] == 0) {
            neighbors[neighbors_length] = Node(x, y + 1, d, cnt + 1);
            neighbors_length++;

            if (y + 2 < m && map[x][y + 2] == 0) {
                neighbors[neighbors_length] = Node(x, y + 2, d, cnt + 1);
                neighbors_length++;

                if (y + 3 < m && map[x][y + 3] == 0) {
                    neighbors[neighbors_length] = Node(x, y + 3, d, cnt + 1);
                    neighbors_length++;
                }
            }
        }

        neighbors[neighbors_length] = Node(x, y, 3, cnt + 1);
        neighbors_length++;

        neighbors[neighbors_length] = Node(x, y, 4, cnt + 1);
        neighbors_length++;
    }

    if (d == 2) {
        if (y - 1 >= 0 && map[x][y - 1] == 0) {
            neighbors[neighbors_length] = Node(x, y - 1, d, cnt + 1);
            neighbors_length++;

            if (y - 2 >= 0 && map[x][y - 2] == 0) {
                neighbors[neighbors_length] = Node(x, y - 2, d, cnt + 1);
                neighbors_length++;

                if (y - 3 >= 0 && map[x][y - 3] == 0) {
                    neighbors[neighbors_length] = Node(x, y - 3, d, cnt + 1);
                    neighbors_length++;
                }
            }
        }

        neighbors[neighbors_length] = Node(x, y, 3, cnt + 1);
        neighbors_length++;

        neighbors[neighbors_length] = Node(x, y, 4, cnt + 1);
        neighbors_length++;
    }

    if (d == 3) {
        if (x + 1 < n && map[x + 1][y] == 0) {
            neighbors[neighbors_length] = Node(x + 1, y, d, cnt + 1);
            neighbors_length++;

            if (x + 2 < n && map[x + 2][y] == 0) {
                neighbors[neighbors_length] = Node(x + 2, y, d, cnt + 1);
                neighbors_length++;

                if (x + 3 < n && map[x + 3][y] == 0) {
                    neighbors[neighbors_length] = Node(x + 3, y, d, cnt + 1);
                    neighbors_length++;
                }
            }
        }

        neighbors[neighbors_length] = Node(x, y, 1, cnt + 1);
        neighbors_length++;

        neighbors[neighbors_length] = Node(x, y, 2, cnt + 1);
        neighbors_length++;
    }

    if (d == 4) {
        if (x - 1 >= 0 && map[x - 1][y] == 0) {
            neighbors[neighbors_length] = Node(x - 1, y, d, cnt + 1);
            neighbors_length++;

            if (x - 2 >= 0 && map[x - 2][y] == 0) {
                neighbors[neighbors_length] = Node(x - 2, y, d, cnt + 1);
                neighbors_length++;

                if (x - 3 >= 0 && map[x - 3][y] == 0) {
                    neighbors[neighbors_length] = Node(x - 3, y, d, cnt + 1);
                    neighbors_length++;
                }
            }
        }

        neighbors[neighbors_length] = Node(x, y, 1, cnt + 1);
        neighbors_length++;

        neighbors[neighbors_length] = Node(x, y, 2, cnt + 1);
        neighbors_length++;
    }


}

void bfs() {
    queue<node> q;

    q.push(start);

    bool explored[105][105][5];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (int k = 0; k < 5; k++) {
                explored[i][j][k] = false;
            }
        }
    }

    explored[start.x][start.y][start.d] = true;

    while(true) {
        if (q.empty()) {
            break;
        }

        node f = q.front();

        q.pop();

        if (f.x == target.x && f.y == target.y && f.d == target.d) {
            cout << f.cnt;
            break;
        }

        get_possible_actions(f);

        for (int i = 0; i < neighbors_length; i++) {
            if (!explored[neighbors[i].x][neighbors[i].y][neighbors[i].d]) {
                q.push(neighbors[i]);
                explored[neighbors[i].x][neighbors[i].y][neighbors[i].d] = true;
            }
        }
    }
}

int main() {
    input();

    bfs();

    return 0;
}
