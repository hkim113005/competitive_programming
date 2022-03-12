#include <iostream>
#include <queue>

using namespace std;

struct node {
    int x;
    node* p;
};

int n, k;
int s, t;
bool b[1005][35];
int roads_len = 0;
int roads[100005][2];

void input() {
    cin >> n >> k;

    for (int i = 0; i < n; i++) {
        string t;

        cin >> t;

        for (int j = 0; j < k; j++) {
            b[i][j] = t[j] - '0';
        }
    }

    cin >> s >> t;
}

void find_roads() {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int cnt = 0;

            for (int l = 0; l < k; l++) {
                if (b[i][l] ^ b[j][l]) {
                    cnt++;
                }
            }

            if (cnt == 1) {
                roads[roads_len][0] = i;
                roads[roads_len][1] = j;

                roads_len++;
            }
        }
    }
}

node make_node(int x, node* p) {
    node N;
    N.x = x;
    N.p = p;
    return N;
}

void bfs(int start, int target) {
    queue<node> q;

    q.push(make_node(start, nullptr));

    bool explored[100000];

    for (int i = 0; i <= n; i++) {
        explored[i] = false;
    }

    explored[start] = true;

    while (true) {
        if (q.empty()) {
            cout << -1;

            return;
        }

        node f = q.front();

        q.pop();

        if (f.x == target) {
            node e = f;

            int ans_len = 0;
            int ans[1005];

            while (true) {
                ans[ans_len] = e.x;
                ans_len++;

                if (e.p == nullptr) {
                    for (int i = ans_len - 1; i >= 0; i--) {
                        cout << ans[i] + 1 << " ";
                    }
                    return;
                }

                e = *e.p;
            }
        }

        for (int i = 0; i < roads_len; i++) {
            if (roads[i][0] == f.x && !explored[roads[i][1]]) {
                node *e = new node;
                e->x = f.x;
                e->p = f.p;

                q.push(make_node(roads[i][1], e));

                explored[roads[i][1]] = true;
            }

            if (roads[i][1] == f.x && !explored[roads[i][0]]) {
                node *e = new node;
                e->x = f.x;
                e->p = f.p;

                q.push(make_node(roads[i][0], e));

                explored[roads[i][0]] = true;
            }
        }
    }
}

int main() {
    input();

    find_roads();

    bfs(s - 1, t - 1);

    return 0;
}
