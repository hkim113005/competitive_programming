#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct node {
    int x, y;
    int cnt = 0;

    node(int x, int y, int cnt) {
        this->x = x;
        this->y = y;
        this->cnt = cnt;
    }
};

char map[55][55];
char cur_map[55][55];
int N, M;
int max_cnt = 0;
node ans1 = node(0, 0, 0);
node ans2 = node(0, 0, 0);

void input() {
    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> map[i][j];
        }
    }
}

vector<node> get_neighbors(node cur) {
    vector<node> neighbors;

    int x = cur.x;
    int y = cur.y;
    int cnt = cur.cnt;

    if (x - 1 >= 0) {
        if (cur_map[x - 1][y] == 'L') {
            neighbors.emplace_back(node(x - 1, y, cnt + 1));
        }
    }

    if (x + 1 < N) {
        if (cur_map[x + 1][y] == 'L') {
            neighbors.emplace_back(node(x + 1, y, cnt + 1));
        }
    }

    if (y - 1 >= 0) {
        if (cur_map[x][y - 1] == 'L') {
            neighbors.emplace_back(node(x, y - 1, cnt + 1));
        }
    }

    if (y + 1 < M) {
        if (cur_map[x][y + 1] == 'L') {
            neighbors.emplace_back(node(x, y + 1, cnt + 1));
        }
    }

    return neighbors;
}

void solve(int x, int y) {
    queue<node> frontier;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cur_map[i][j] = map[i][j];
        }
    }

    node possible_ans_1 = node(x, y, 0);
    node possible_ans_2 = node(0, 0, 0);

    frontier.push(node(x, y, 0));

    while (true) {
        if (frontier.empty()) {
            if (possible_ans_2.cnt > max_cnt) {
                max_cnt = possible_ans_2.cnt;

                ans1.x = possible_ans_1.x;
                ans1.y = possible_ans_1.y;
                ans1.cnt = possible_ans_1.cnt;

                ans2.x = possible_ans_2.x;
                ans2.y = possible_ans_2.y;
                ans2.cnt = possible_ans_2.cnt;
            }

            return;
        }

        node front = frontier.front();

        frontier.pop();

        cur_map[front.x][front.y] = 'X';

        if (front.cnt > possible_ans_2.cnt) {
            possible_ans_2.x = front.x;
            possible_ans_2.y = front.y;
            possible_ans_2.cnt = front.cnt;
        }

        vector<node> neighbors = get_neighbors(front);

        for (int i = 0; i < (int)neighbors.size(); i++) {
            frontier.push(neighbors[i]);
        }
    }
}

int main() {
    input();

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (map[i][j] == 'L') {
                solve(i, j);
            }
        }
    }

    cout << ans2.cnt;

    return 0;
}
