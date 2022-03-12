#include <iostream>
#include <queue>

using namespace std;

struct node {
    int state, level;
};

int N, S, D, F, B, K;
bool explored[100005] = { false };

void bfs() {
    node start{};
    start.state = S;
    start.level = 0;

    queue<node> frontier;
    frontier.push(start);

    explored[start.state] = true;

    while (true) {
        if (frontier.empty()) {
            cout << "BUG FOUND";

            return;
        }

        node front = frontier.front();
        frontier.pop();

        if (front.state == D) {
            cout << front.level;

            return;
        }

        node n{};
        if (front.state + F <= N) {
            if (!explored[front.state + F]) {
                n.state = front.state + F;
                n.level = front.level + 1;

                frontier.push(n);

                explored[front.state + F] = true;
            }
        }

        if (front.state - B > 0) {
            if (!explored[front.state - B]) {
                n.state = front.state - B;
                n.level = front.level + 1;

                frontier.push(n);

                explored[front.state - B] = true;
            }
        }
    }
}

int main() {
    cin >> N >> S >> D >> F >> B >> K;

    for (int i = 0; i < K; i++) {
        int tmp;

        cin >> tmp;

        explored[tmp] = true;
    }

    bfs();


    return 0;
}
