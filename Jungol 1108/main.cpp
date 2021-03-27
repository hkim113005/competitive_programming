#include <iostream>
#include <math.h>
#include <queue>
#include <iomanip>

#define MAX 500

using namespace std;

int N, P = 0, paths[MAX][2];

int bfs(int s) {
    queue<pair<int, int>> frontier;
    frontier.push(make_pair(s, 0));

    bool explored[MAX];
    for (int i = 1; i <= P; i++) {
        explored[i] = false;
    }
    explored[s] = true;

    int total = 0;

    while (true) {
        if (frontier.empty()) {
            return total;
        }

        pair<int, int> front = frontier.front();
        frontier.pop();

        for (int i = 0; i < N; i++) {
            if (front.first == paths[i][0] && !explored[paths[i][1]]) {
                frontier.push(make_pair(paths[i][1], front.second + 1));
                explored[paths[i][1]] = true;

                total += front.second + 1;
            }
        }
    }
}

int main() {
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> paths[i][0] >> paths[i][1];

        if (P < paths[i][0]) {
            P = paths[i][0];
        }
    }

    double ans = 0;

    for (int i = 1; i <= P; i++) {
        ans += bfs(i);
    }

    //cout << "Total: " << ans << endl;
    //cout << "Paths: " << P * (P - 1) << endl;
    printf("%.3lf", ans / (P * (P - 1)));

    return 0;
}
