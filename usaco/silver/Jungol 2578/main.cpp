#include <iostream>
#include <queue>

using namespace std;

struct node {
    int x, y, cnt;
};

queue<node> q;
int n, m;
int k;
int bus[5005][2][2];
node start, target;
bool explored[5005];

void input() {
    cin >> n >> m;

    cin >> k;

    for (int i = 0; i < k; i++) {
        int t;
        cin >> t >> bus[i][0][0] >> bus[i][0][1] >> bus[i][1][0] >> bus[i][1][1];
    }

    cin >> start.x >> start.y >> target.x >> target.y;

    start.cnt = 0;
}

node Node(int x, int y, int cnt) {
    node N;
    N.x = x;
    N.y = y;
    N.cnt = cnt;
    return N;
}

void find_possible_actions(node f) {
    int x = f.x;
    int y = f.y;
    int cnt = f.cnt;

    for (int i = 0; i < k; i++) {
        if (bus[i][0][0] == x && bus[i][1][0] == x && bus[i][0][1] <= y && y <= bus[i][1][1] && !explored[i]) {
            for (int j = bus[i][0][1]; j <= bus[i][1][1]; j++) {
                q.push(Node(x, j, cnt + 1));
            }

            explored[i] = true;
        }

        if (bus[i][0][1] == y && bus[i][1][1] == y && bus[i][0][0] <= x && x <= bus[i][1][0] && !explored[i]) {
            for (int j = bus[i][0][0]; j <= bus[i][1][0]; j++) {
                q.push(Node(j, y, cnt + 1));
            }

            explored[i] = true;
        }
    }
}

void bfs() {
    q.push(start);

    for (int i = 0; i <= n; i++) {
        explored[i] = false;
    }

    while (true) {
        if (q.empty()) {
            break;
        }

        node f = q.front();

        q.pop();

        if (f.x == target.x && f.y == target.y) {
            cout << f.cnt;

            break;
        }

        find_possible_actions(f);
    }
}

int main() {
    input();

    bfs();

    return 0;
}
