#include <iostream>
#include <queue>

using namespace std;

int N, P = 0, paths[1255][2];

int bfs(int s) {
    queue<pair<int, int>> frontier;

    frontier.push(make_pair(s, 0));

    bool explored[55];

    for (int i = 1; i <= N; i++) {
        explored[i] = false;
    }

    explored[s] = true;

    int point = 0;

    while (true) {
        if (frontier.empty()) {
            return point;
        }

        pair<int, int> front = frontier.front();

        frontier.pop();

        for (int i = 0; i < P; i++) {
            if (paths[i][0] == front.first && !explored[paths[i][1]]) {
                frontier.push(make_pair(paths[i][1], front.second + 1));
                explored[paths[i][1]] = true;

                if (point < front.second + 1) {
                    point = front.second + 1;
                }
            }

            if (paths[i][1] == front.first && !explored[paths[i][0]]) {
                frontier.push(make_pair(paths[i][0], front.second + 1));
                explored[paths[i][0]] = true;

                if (point < front.second + 1) {
                    point = front.second + 1;
                }
            }
        }
    }
}

int main() {
    cin >> N;

    int a = 0, b = 0;
    while (true) {
        cin >> a >> b;

        if (a == -1 && b == -1) {
            break;
        }

        paths[P][0] = a;
        paths[P][1] = b;

        P++;
    }

    vector<int> ans;
    int min_points = 55;

    for (int i = 1; i <= N; i++) {
        int t = bfs(i);

        if (min_points > t) {
            min_points = t;
            ans.clear();
            ans.emplace_back(i);
        }
        else if (min_points == t) {
            ans.emplace_back(i);
        }
    }

    cout << min_points << " " << ans.size() << endl;
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}
