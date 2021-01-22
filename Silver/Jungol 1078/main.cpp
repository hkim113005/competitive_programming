#include <iostream>
#include <vector>

using namespace std;

typedef struct Pos {
    int x, y;

    friend bool operator== (Pos& lhs, Pos& rhs);
    friend bool operator!= (Pos& lhs, Pos& rhs);
} Pos;

bool operator== (Pos& lhs, Pos& rhs) {
    return (lhs.x == rhs.x && lhs.y == rhs.y);
}
bool operator!= (Pos& lhs, Pos& rhs) {
    return !(lhs.x == rhs.x && lhs.y == rhs.y);
}

class Node {
public:
    Pos state = create_pos(0, 0);
    Node* parent;
    int cnt;

    Node(Pos s, Node* p, int c) {
        state = s;
        parent = p;
        cnt = c;
    }

    Pos create_pos(int a, int b) {
        Pos pos;
        pos.x = a;
        pos.y = b;
        return pos;
    }

    friend bool operator== (Node& lhs, Node& rhs);
};

bool operator== (Node& lhs, Node& rhs) {
    return (lhs.state == rhs.state && lhs.parent == rhs.parent);
}

class QueueFrontier {
private:
    vector<Node> frontier;
    int size = 0;

public:
    QueueFrontier(int n) {
        frontier = vector<Node>(n, Node(create_pos(-1, -1), nullptr, 0));
    }

    void add(Node node) {
        frontier[size].state = node.state;
        frontier[size].parent = node.parent;
        frontier[size].cnt = node.cnt;
        size++;
    }

    bool contains_state(Pos state) {
        for (int i = 0; i < size; i++) {
            if (state == frontier[i].state) {
                return true;
            }
        }

        return false;
    }

    bool empty() {
        if (size == 0) {
            return true;
        }
        else {
            return false;
        }
    }

    Node remove() {
        if (empty()) {
            throw exception("empty frontier");
        }
        else {
            Node r = frontier[0];

            vector<Node> new_frontier(frontier.size(), Node(create_pos(-1, -1), nullptr, 0));

            for (int i = 1; i < frontier.size(); i++) {
                new_frontier[i - 1] = frontier[i];
            }

            frontier = new_frontier;

            size--;

            return r;
        }
    }

    Pos create_pos(int a, int b) {
        Pos pos;
        pos.x = a;
        pos.y = b;
        return pos;
    }
};

class Jugglers {
public:
    int n, m, max_count = 0;
    vector<vector<int>> jugglers;

    Jugglers(int a, int b) {
        n = a;
        m = b;

        jugglers.resize(m);

        for (int i = 0; i < m; i++) {
            jugglers[i].resize(n);

            string tmp;
            cin >> tmp;

            for (int j = 0; j < n; j++) {
                jugglers[i][j] = tmp[j] - '0';
            }
        }
    }

    void print() {
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                cout << jugglers[i][j] << " ";
            }

            cout << endl;
        }

        cout << endl << endl;
    }

    vector<Pos> neighbors(Pos cur) {
        vector<Pos> neighbors;

        if (cur.x - 1 >= 0) {
            if (jugglers[cur.x - 1][cur.y] == 1) {
                neighbors.push_back(create_pos(cur.x - 1, cur.y));
            }
        }

        if (cur.x + 1 < m) {
            if (jugglers[cur.x + 1][cur.y] == 1) {
                neighbors.push_back(create_pos(cur.x + 1, cur.y));
            }
        }

        if (cur.y - 1 >= 0) {
            if (jugglers[cur.x][cur.y - 1] == 1) {
                neighbors.push_back(create_pos(cur.x, cur.y - 1));
            }
        }

        if (cur.y + 1 < n) {
            if (jugglers[cur.x][cur.y + 1] == 1) {
                neighbors.push_back(create_pos(cur.x, cur.y + 1));
            }
        }

        return neighbors;
    }

    void solve(int a, int b) {
        int prev_cnt = 0;

        Node start = Node(create_pos(a, b), nullptr, 1);
        start.cnt = 1;

        QueueFrontier frontier = QueueFrontier(n * m);

        frontier.add(start);

        vector<Pos> explored(n * m);

        while (true) {
            if (frontier.empty()) {
                return;
            }

            Node node = frontier.remove();
            explored.push_back(node.state);

            if (node.cnt > prev_cnt) {
                print();
                prev_cnt = node.cnt;
            }

            jugglers[node.state.x][node.state.y] = node.cnt;

            vector<Pos> neighbor_states = neighbors(node.state);

            if (neighbor_states.size() == 0) {
                int count = 0;

                while (node.parent != nullptr) {
                    count++;
                    node.state = node.parent->state;
                    node.parent = node.parent->parent;
                }

                max_count = max(max_count, count);
            }

            for (int i = 0; i < neighbor_states.size(); i++) {
                if (!frontier.contains_state(neighbor_states[i])) {
                    bool in_explored = false;

                    for (int j = 0; j < explored.size(); j++) {
                        if (explored[j] == neighbor_states[i]) {
                            in_explored = true;
                            break;
                        }
                    }

                    if (!in_explored) {
                        Node *p = new Node(node.state, node.parent, 1);
                        Node child = Node(neighbor_states[i], p, node.cnt + 1);
                        frontier.add(child);
                    }
                }
            }
        }
    }

    Pos create_pos(int a, int b) {
        Pos pos;
        pos.x = a;
        pos.y = b;
        return pos;
    }
};

int main() {
    int n, m;

    cin >> n >> m;

    Jugglers jugglers(n, m);

    int x, y;

    cin >> x >> y;

    jugglers.solve(y - 1, x - 1);

    cout << jugglers.max_count + 3;

    return 0;
}
