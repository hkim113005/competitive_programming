#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

struct node {
    int x, y;
    int cnt = 0;

    node(int x, int y, int cnt) {
        this->x = x;
        this->y = y;
        this->cnt = cnt;
    }

    bool operator==(node const & a) const {
        return a.x == this->x && a.y == this->y;
    }
};

char map[55][55];
char cur_map[55][55];
int N, M;
int max_cnt = 0;
node ans1 = node(0, 0, 0);
node ans2 = node(0, 0, 0);
int neighbors[4][3];
int explored[3000][2];
int explored_len = 0;

void input() {
    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> map[i][j];
        }
    }
}

int get_neighbors(node cur) {
    int x = cur.x;
    int y = cur.y;
    int cnt = cur.cnt;

    int len = 0;

    if (x - 1 >= 0) {
        if (cur_map[x - 1][y] == 'L') {
            neighbors[len][0] = x - 1;
            neighbors[len][1] = y;
            neighbors[len][2] = cnt + 1;

            len++;
        }
    }

    if (x + 1 < N) {
        if (cur_map[x + 1][y] == 'L') {
            neighbors[len][0] = x + 1;
            neighbors[len][1] = y;
            neighbors[len][2] = cnt + 1;

            len++;
        }
    }

    if (y - 1 >= 0) {
        if (cur_map[x][y - 1] == 'L') {
            neighbors[len][0] = x;
            neighbors[len][1] = y - 1;
            neighbors[len][2] = cnt + 1;

            len++;
        }
    }

    if (y + 1 < M) {
        if (cur_map[x][y + 1] == 'L') {
            neighbors[len][0] = x;
            neighbors[len][1] = y + 1;
            neighbors[len][2] = cnt + 1;

            len++;
        }
    }

    return len;
}

bool in(int x, int y) {
    for (int i = 0; i < explored_len; i++) {
        if (explored[i][0] == x && explored[i][1] == y) {
            return true;
        }
    }

    return false;
}

void print() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cout << cur_map[i][j] << " ";
        }

        cout << endl;
    }

    cout << endl << endl;
}

void solve(int x, int y) {
    queue<node> frontier;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cur_map[i][j] = map[i][j];
        }
    }

    int possible_ans = 0;

    frontier.push(node(x, y, 0));

    explored_len = 0;

    explored[explored_len][0] = x;
    explored[explored_len][1] = y;

    explored_len++;

    while (true) {
        if (frontier.empty()) {
            if (possible_ans > max_cnt) {
                max_cnt = possible_ans;
            }

            return;
        }

        node front = frontier.front();

        frontier.pop();

        cur_map[front.x][front.y] = 'X';

        if (front.cnt > possible_ans) {
            possible_ans = front.cnt;
        }

        int len = get_neighbors(front);

        for (int i = 0; i < len; i++) {
            if (!in(neighbors[i][0], neighbors[i][1])) {
                frontier.push(node(neighbors[i][0], neighbors[i][1], neighbors[i][2]));
                explored[explored_len][0] = neighbors[i][0];
                explored[explored_len][1] = neighbors[i][1];

                explored_len++;
            }
        }
    }
}

int main() {
    input();

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (map[i][j] == 'L') {
                int k = 0;

                if (i - 1 >= 0) {
                    if (map[i - 1][j] == 'L') {
                        k++;
                    }
                }

                if (i + 1 < N) {
                    if (map[i + 1][j] == 'L') {
                        k++;
                    }
                }

                if (j - 1 >= 0) {
                    if (map[i][j - 1] == 'L') {
                        k++;
                    }
                }

                if (j + 1 < M) {
                    if (map[i][j + 1] == 'L') {
                        k++;
                    }
                }

                if (k == 1 || k == 2) {
                    solve(i, j);
                }
            }
        }
    }

    cout << max_cnt;

    return 0;
}