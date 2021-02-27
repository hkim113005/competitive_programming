#include <iostream>
#include <queue>
#include <math.h>

using namespace std;

int N;
int roads[100000][2];

void bfs() {
    queue<int> q;

    int t = 0;

    q.push(1);

    bool explored[100000];

    for (int i = 0; i <= N; i++) {
        explored[i] = false;
    }

    explored[1] = true;

    while (true) {
        if (q.empty()) {
            cout << t;

            return;
        }

        int f = q.front();

        q.pop();

        int cnt = 0;

        for (int i = 0; i < N - 1; i++) {
            if (roads[i][0] != f && roads[i][1] != f) {
                continue;
            }
            if (roads[i][0] == f && !explored[roads[i][1]]) {
                q.push(roads[i][1]);
                explored[roads[i][1]] = true;
                t++;
                cnt++;
            }
            else if (roads[i][1] == f && !explored[roads[i][0]]) {
                q.push(roads[i][0]);
                explored[roads[i][0]] = true;
                t++;
                cnt++;
            }
        }

        if (cnt != 0) {
            t += ceil(log(cnt + 1) / log(2));
        }
    }
}

int main() {
    cin >> N;

    for (int i = 0; i < N - 1; i++) {
        cin >> roads[i][0] >> roads[i][1];
    }

    bfs();

    return 0;
}
