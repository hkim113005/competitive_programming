#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

class Node {
public:
    int current;
    vector<Node> children;

    friend bool operator== (Node& lhs, Node& rhs);
};

bool operator== (Node& lhs, Node& rhs) {
    if (lhs.children.size() == rhs.children.size()) {
        for (int i = 0; i < lhs.children.size(); i++) {
            if (lhs.children[i].current != rhs.children[i].current) {
                return false;
            }
        }

        if (lhs.current != rhs.current) {
            return false;
        }
    }
    else {
        return false;
    }

    return true;
}

class QueueFrontier {
public:
    vector<Node> frontier;

    void add(Node node) {
        frontier.push_back(node);
    }

    Node remove() {
        Node r = frontier[0];

        frontier = vector<Node>(frontier.begin() + 1, frontier.end());

        return r;
    }

    bool empty() {
        if (frontier.size() == 0) {
            return true;
        }

        return false;
    }

    bool contains(Node node) {
        for (int i = 0; i < frontier.size(); i++) {
            if (frontier[i] ==  node) {
                return true;
            }
        }

        return false;
    }
};

class Farm {
public:
    int n;
    vector<Node> paths;

    int num_explored;
    int moves;
    vector<int> explored;

    Farm() {
        cin >> n;

        paths.resize(n + 1);

        for (int i = 1; i <= n; i++) {
            paths[i].current = i;
        }

        for (int i = 0; i < n - 1; i++) {
            int t1, t2;

            cin >> t1 >> t2;

            paths[t1].children.push_back(paths[t2]);
        }
    }

    vector<Node> neighbors(int cur) {
        vector<Node> neighbors;

        for (int i = 0; i < paths[cur].children.size(); i++) {
            neighbors.push_back(paths[cur].children[i]);
        }

        return neighbors;
    }

    void solve() {
        num_explored = 0;
        moves = 0;

        Node start;
        start.current = 1;
        start.children = paths[1].children;

        QueueFrontier frontier;

        frontier.add(start);

        while (true) {
            if (explored.size() == paths.size() - 1) {
                return;
            }

            if (frontier.empty()) {
                return;
            }

            Node node = frontier.remove();
            explored.push_back(node.current);
            num_explored++;

            vector<Node> neighbors = this->neighbors(node.current);

            int unexplored = 0;

            for (int i = 0; i < neighbors.size(); i++) {
                if (!frontier.contains(neighbors[i])) {
                    bool in_explored = false;

                    for (int j = 0; j < num_explored; j++) {
                        if (explored[j] == neighbors[i].current) {
                            in_explored = true;
                            break;
                        }
                    }

                    if (!in_explored) {
                        unexplored++;
                        frontier.add(neighbors[i]);
                        moves++;
                    }
                }
            }

            if (unexplored != 0) {
                double sqr = sqrt(unexplored + 1);
                int a;

                if (sqr - (int) (sqr) == 0) {
                    a = sqr;
                } else {
                    a = sqr + 1;
                }

                moves += a;
            }
        }
    }
};

int main() {
    Farm farm;

    farm.solve();

    cout << farm.moves;

    return 0;
}
