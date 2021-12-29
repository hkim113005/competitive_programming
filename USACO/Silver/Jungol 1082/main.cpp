#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct Node {
    int x, y;
    int cnt;

    bool operator==(const Node& a) const {
        return (x == a.x && y == a.y && cnt == a.cnt);
    }
};

int r, c;
char e[1000][1000];

Node start;
Node finish;
vector<Node> fire;

vector<Node> find_neighbors(int x, int y, int cnt) {
    vector<Node> neighbors;

    Node tmp;

    tmp.cnt = cnt + 1;

    if (x - 1 >= 0) {
        if (e[x - 1][y] == '.' || e[x - 1][y] == 'D') {
            tmp.x = x - 1;
            tmp.y = y;
            neighbors.emplace_back(tmp);
        }
    }

    if (x + 1 < r) {
        if (e[x + 1][y] == '.' || e[x + 1][y] == 'D') {
            tmp.x = x + 1;
            tmp.y = y;
            neighbors.emplace_back(tmp);
        }
    }

    if (y - 1 >= 0) {
        if (e[x][y - 1] == '.' || e[x][y - 1] == 'D') {
            tmp.x = x;
            tmp.y = y - 1;
            neighbors.emplace_back(tmp);
        }
    }

    if (y + 1 < c) {
        if (e[x][y + 1] == '.' || e[x][y + 1] == 'D') {
            tmp.x = x;
            tmp.y = y + 1;
            neighbors.emplace_back(tmp);
        }
    }

    return neighbors;
}

void print() {
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cout << e[i][j] << " ";
        }

        cout << endl;
    }

    cout << endl << endl;
}

void solve() {
    int cur_cnt = -1;

    queue<Node> frontier;

    frontier.push(start);

    vector<Node> explored;

    explored.push_back(start);

    while (true) {
        if (frontier.empty()) {
            cout << "impossible";
            return;
        }

        Node node = frontier.front();

        frontier.pop();

        if (node.cnt == cur_cnt + 1) {
            //print();

            vector<Node> new_fire;

            for (int i = 0; i < (int)fire.size(); i++) {
                if (fire[i].x - 1 >= 0) {
                    if (e[fire[i].x - 1][fire[i].y] == '.') {
                        Node f;
                        f.x = fire[i].x - 1;
                        f.y = fire[i].y;
                        f.cnt = 0;

                        new_fire.push_back(f);

                        e[f.x][f.y] = '*';
                    }
                }

                if (fire[i].x + 1 < r) {
                    if (e[fire[i].x + 1][fire[i].y] == '.') {
                        Node f;
                        f.x = fire[i].x + 1;
                        f.y = fire[i].y;
                        f.cnt = 0;

                        new_fire.push_back(f);

                        e[f.x][f.y] = '*';
                    }
                }

                if (fire[i].y - 1 >= 0) {
                    if (e[fire[i].x][fire[i].y - 1] == '.') {
                        Node f;
                        f.x = fire[i].x;
                        f.y = fire[i].y - 1;
                        f.cnt = 0;

                        new_fire.push_back(f);

                        e[f.x][f.y] = '*';
                    }
                }

                if (fire[i].y + 1 < c) {
                    if (e[fire[i].x][fire[i].y + 1] == '.') {
                        Node f;
                        f.x = fire[i].x;
                        f.y = fire[i].y + 1;
                        f.cnt = 0;

                        new_fire.push_back(f);

                        e[f.x][f.y] = '*';
                    }
                }
            }

            for (int i = 0; i < (int)new_fire.size(); i++) {
                fire.push_back(new_fire[i]);
            }

        cur_cnt = node.cnt;
        }

        if (e[node.x][node.y] == 'D') {
            cout << node.cnt;
            return;
        }

        e[node.x][node.y] = 'O';

        vector<Node> neighbors = find_neighbors(node.x, node.y, node.cnt);

        for (int i = 0; i < (int)neighbors.size(); i++) {
            if (count(explored.begin(), explored.end(), neighbors[i]) == 0) {
                frontier.push(neighbors[i]);

                explored.emplace_back(neighbors[i]);
            }
        }
    }
}

void input() {
    cin >> r >> c;

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> e[i][j];

            if (e[i][j] == 'S') {
                start.x = i;
                start.y = j;
                start.cnt = 0;
            }

            if (e[i][j] == 'D') {
                finish.x = i;
                finish.y = j;
                finish.cnt = 0;
            }

            if (e[i][j] == '*') {
                Node node;
                node.x = i;
                node.y = j;
                node.cnt = 0;

                fire.push_back(node);
            }
        }
    }
}

int main() {
    input();

    solve();

    return 0;
}
