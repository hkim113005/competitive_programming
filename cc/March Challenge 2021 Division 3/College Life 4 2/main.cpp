#include <iostream>

using namespace std;

struct node {
    int cost;
    char now;
    char next;
};

void solve() {
    int N, E, H, A, B, C;
    node order[3];

    cin >> N >> E >> H >> A >> B >> C;

    if (A <= B && A <= C) {
        order[0].cost = A;
        order[0].now = 'A';

        if (B < C) {
            order[0].next = 'B';
            order[1].cost = B;
            order[1].now = 'B';

            order[1].next = 'C';
            order[2].cost = C;
            order[2].now = 'C';
        }
        else {
            order[0].next = 'C';
            order[1].cost = C;
            order[1].now = 'C';

            order[1].next = 'B';
            order[2].cost = B;
            order[2].now = 'B';
        }
    }
    else if (B <= A && B <= C) {
        order[0].cost = B;
        order[0].now = 'B';

        if (A < C) {
            order[0].next = 'A';
            order[1].cost = A;
            order[1].now = 'A';

            order[1].next = 'C';
            order[2].cost = C;
            order[2].now = 'C';
        }
        else {
            order[0].next = 'C';
            order[1].cost = C;
            order[1].now = 'C';

            order[1].next = 'A';
            order[2].cost = A;
            order[2].now = 'A';
        }
    }
    else if (C <= A && C <= B) {
        order[0].cost = C;
        order[0].now = 'C';

        if (A < B) {
            order[0].next = 'A';
            order[1].cost = A;
            order[1].now = 'A';

            order[1].next = 'B';
            order[2].cost = B;
            order[2].now = 'B';
        }
        else {
            order[0].next = 'B';
            order[1].cost = B;
            order[1].now = 'B';

            order[1].next = 'A';
            order[2].cost = A;
            order[2].now = 'A';
        }
    }

    int cur = 0, ans = 0;

    for (int i = 0; i < N; i++) {
        int now, next;
        int next_E, next_H;

        next_E = E;
        next_H = H;

        if (order[cur].now == 'A') {
            next_E -= 2;

            now = next_E / 2;
        }
        else if (order[cur].now == 'B') {
            next_H -= 3;

            now = next_H / 3;
        }
        else if (order[cur].now == 'C') {
            next_E--;
            next_H--;

            now = min(next_E, next_H);
        }

        int t;

        if (order[cur].next == 'A') {
            next = next_E / 2;
            t = 2;
        }
        else if (order[cur].next == 'B') {
            next = next_H / 3;
            t = 3;
        }
        else if (order[cur].next == 'C') {
            next = min(next_E, next_H);
            t = 1;
        }
        else {
            next = now;
        }

        if (cur == 0) {
            if (order[cur + 1].next == 'A') {
                if (t == 1) {
                    next += (next_E - next) / 2;
                }
                else {
                    next += next_E / 2;
                }
            }
            else if (order[cur + 1].next == 'B') {
                if (t == 1) {
                    next += (next_H - next) / 3;
                }
                else {
                    next += next_H / 3;
                }
            }
            else if (order[cur + 1].next == 'C') {
                if (t == 2) {
                    next += min(next_E - t * next, next_H);
                }
                else {
                    next += min(next_E, next_H - t * next);
                }
            }
            else {
                next = now;
            }
        }

        if (i + 1 + now < N && i + 1 + next < N) {
            cur++;
        }

        if (cur > 2) {
            cout << -1 << endl;

            return;
        }

        if (order[cur].now == 'A') {
            E -= 2;

            ans += A;

            cout << 'A' << ' ';
        }
        else if (order[cur].now == 'B') {
            H -= 3;

            ans += B;

            cout << 'B' << ' ';
        }
        else if (order[cur].now == 'C') {
            E--;
            H--;

            ans += C;

            cout << 'C' << ' ';
        }
    }

    cout << endl << ans << endl;
}

int main() {
    int T;

    cin >> T;

    while (T--) {
        solve();
    }

    return 0;
}
