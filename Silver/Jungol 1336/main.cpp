#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

struct node {
    int x;
    int t;

    node(int x, int t) {
        this->x = x;
        this->t = t;
    }

    bool operator==(const node& a) const {
        return this->x == a.x;
    }
};

vector<int> prime_numbers;
bool is_prime[10500];
int start;
int finish;

void get_prime_numbers() {
    for (int i = 0; i < 10000; i++) {
        is_prime[i] = true;
    }

    for (int i = 2; i < 10000; i++) {
        if (is_prime[i]) {
            for (int j = 2; j <= 10000 / i; j++) {
                is_prime[i * j] = false;
            }
        }
    }

    for (int i = 2; i < 10000; i++) {
        if (is_prime[i]) {
            prime_numbers.emplace_back(i);
        }
    }
}

vector<node> get_neighbors(int x, int t) {
    vector<node> neighbors;

    for (int i = 0; i < prime_numbers.size(); i ++) {
        int same = 0;

        int t1 = prime_numbers[i];
        int t2 = x;

        for (int j = 0; j < 4; j++) {
            if (t1 % 10 == t2 % 10) {
                same++;
            }

            t1 /= 10;
            t2 /= 10;

            if (t2 == 0) {
                break;
            }
        }

        if (same == 3) {
            neighbors.emplace_back(node(prime_numbers[i], t + 1));
        }
    }

    return neighbors;
}

void solve() {
    queue<node> frontier;

    frontier.push(node(start, 0));

    vector<node> explored;

    explored.emplace_back(node(start, 0));

    while (true) {
        if (frontier.empty()) {
            return;
        }

        node cur = frontier.front();

        frontier.pop();

        if (cur.x == finish) {
            cout << cur.t;

            return;
        }

        vector<node> neighbors = get_neighbors(cur.x, cur.t);

        for (int i = 0; i < (int)neighbors.size(); i++) {
            if (count(explored.begin(), explored.end(), neighbors[i]) == 0) {
                frontier.push(neighbors[i]);
                explored.emplace_back(neighbors[i]);
            }
        }
    }
}

int main() {
    cin >> start >> finish;

    get_prime_numbers();

    solve();

    return 0;
}
