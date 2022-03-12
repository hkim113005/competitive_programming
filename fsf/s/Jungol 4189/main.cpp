#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

bool board[1005][1005];
int neighbors[10][3];
int N, M;
int start_x, start_y, end_x, end_y;

void print() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cout << board[i][j] << " ";
        }

        cout << endl;
    }

    cout << endl << endl;
}

void input() {
    for (int i = 0; i < 1005; i++) {
        for (int j = 0; j < 1005; j++) {
            board[i][j] = false;
        }
    }

    cin >> N >> M;

    cin >> start_x >> start_y >> end_x >> end_y;
}

int get_neighbors(int x, int y, int c) {
    int cnt = 0;

    if (x - 2 > 0) {
        if (y - 1 > 0) {
            if (!board[x - 2][y - 1]) {
                neighbors[cnt][0] = x - 2;
                neighbors[cnt][1] = y - 1;

                cnt++;
            }
        }

        if (y + 1 <= M) {
            if (!board[x - 2][y + 1]) {
                neighbors[cnt][0] = x - 2;
                neighbors[cnt][1] = y + 1;

                cnt++;
            }
        }
    }

    if (x - 1 > 0) {
        if (y - 2 > 0) {
            if (!board[x - 1][y - 2]) {
                neighbors[cnt][0] = x - 1;
                neighbors[cnt][1] = y - 2;

                cnt++;
            }
        }

        if (y + 2 <= M) {
            if (!board[x - 1][y + 2]) {
                neighbors[cnt][0] = x - 1;
                neighbors[cnt][1] = y + 2;

                cnt++;
            }
        }
    }

    if (x + 1 <= N) {
        if (y - 2 > 0) {
            if (!board[x + 1][y - 2]) {
                neighbors[cnt][0] = x + 1;
                neighbors[cnt][1] = y - 2;

                cnt++;
            }
        }

        if (y + 2 <= M) {
            if (!board[x + 1][y + 2]) {
                neighbors[cnt][0] = x + 1;
                neighbors[cnt][1] = y + 2;

                cnt++;
            }
        }
    }

    if (x + 2 <= N) {
        if (y - 1 > 0) {
            if (!board[x + 2][y - 1]) {
                neighbors[cnt][0] = x + 2;
                neighbors[cnt][1] = y - 1;

                cnt++;
            }
        }

        if (y + 1 <= M) {
            if (!board[x + 2][y + 1]) {
                neighbors[cnt][0] = x + 2;
                neighbors[cnt][1] = y + 1;

                cnt++;
            }
        }
    }

    for (int i = 0; i < cnt; i++) {
        neighbors[i][2] = c + 1;
    }

    return cnt;
}

void solve() {
    //print();

    queue<tuple<int, int, int>> frontier;

    frontier.push(make_tuple(start_x, start_y, 0));

    while (true) {
        if (frontier.empty()) {
            return;
        }

        tuple<int, int, int> front = frontier.front();

        frontier.pop();

        if (get<0>(front) == end_x && get<1>(front) == end_y) {
            cout << get<2>(front);

            return;
        }

        int n = get_neighbors(get<0>(front), get<1>(front), get<2>(front));

        for (int i = 0; i < n; i++) {
            board[neighbors[i][0]][neighbors[i][1]] = true;
            frontier.push(make_tuple(neighbors[i][0], neighbors[i][1], neighbors[i][2]));
        }
    }
}

int main() {
    input();

    solve();

    return 0;
}
