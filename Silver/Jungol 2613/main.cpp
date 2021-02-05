#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

struct node {
    int x, y;
    int t;

    node(int x, int y, int t) {
        this->x = x;
        this->y = y;
        this->t = t;
    }

    bool operator==(const node& a) const {
        return (this->x == a.x) && (this->y == a.y);
    }
};

int M, N;
int storage[1005][1005];
vector<node> starts;

void input() {
    cin >> M >> N;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> storage[i][j];

            if (storage[i][j] == 1) {
                starts.emplace_back(i, j, 0);
            }
        }
    }
}

vector<node> get_neighbors(int x, int y, int t) {
    vector<node> neighbors;

    if (x - 1 >= 0) {
        if (storage[x - 1][y] == 0) {
            neighbors.emplace_back(node(x - 1, y, t + 1));
        }
    }

    if (x + 1 < N) {
        if (storage[x + 1][y] == 0) {
            neighbors.emplace_back(node(x + 1, y, t + 1));
        }
    }

    if (y - 1 >= 0) {
        if (storage[x][y - 1] == 0) {
            neighbors.emplace_back(node(x, y - 1, t + 1));
        }
    }

    if (y + 1 < M) {
        if (storage[x][y + 1] == 0) {
            neighbors.emplace_back(node(x, y + 1, t + 1));
        }
    }

    return neighbors;
}

bool check() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (storage[i][j] == 0) {
                return false;
            }
        }
    }

    return true;
}

void print() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (storage[i][j] == -1) {
                printf("X ");
            }
            else if (storage[i][j] == 1) {
                printf("O ");
            }
            else {
                printf("  ");
            }
        }

        cout << endl;
    }

    cout << endl << endl;
}

void solve() {
    int c = 0;

    queue<node> frontier;

    for (int i = 0; i < (int)starts.size(); i++) {
        frontier.push(starts[i]);
    }

    vector<node> explored;

    int level = 0;

    while (true) {
        c++;

        if (frontier.empty()) {
            if (check()) {
                cout << level;
            }
            else {
                cout << "-1";
            }

            return;
        }

        node n = frontier.front();

        frontier.pop();

        explored.emplace_back(n);

        if (level != n.t) {
            //print();

            if (check()) {
                cout << level;

                return;
            }
        }

        level = n.t;

        storage[n.x][n.y] = 1;

        vector<node> neighbors = get_neighbors(n.x, n.y, n.t);

        for (int i = 0; i < (int)neighbors.size(); i++) {
            if (count(explored.begin(), explored.end(), neighbors[i]) == 0) {
                frontier.push(neighbors[i]);
            }
        }
    }
}

int main() {
    input();

    solve();

    return 0;
}

/*
11 11
0 0 0 0 1 0 -1 -1 0 0 0
0 -1 1 1 0 0 1 1 0 0 0
0 0 0 0 -1 1 0 0 1 0 0
0 0 -1 0 0 -1 -1 0 0 0 -1
1 1 -1 0 0 1 0 0 0 -1 1
-1 0 0 0 0 0 1 0 0 1 0
0 1 0 -1 0 0 0 0 1 1 1
0 0 0 1 0 0 0 0 0 -1 0
0 0 0 0 0 0 0 0 0 0 -1
-1 0 0 0 0 0 1 1 0 0 1
-1 0 0 0 0 -1 -1 0 0 0 -1
 */