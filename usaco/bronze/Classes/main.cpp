#include <iostream>
#include <string>
#include <new>
#include <vector>

using namespace std;

typedef struct Pos {
    int x;
    int y;

    friend bool operator== (Pos& lhs, Pos& rhs);
    friend bool operator!= (Pos& lhs, Pos& rhs);

    void setPos(int a, int b) {
        x = a;
        y = b;
    }
} Pos;

bool operator== (Pos& lhs, Pos& rhs) {
    return (lhs.x == rhs.x && lhs.y == rhs.y);
}
bool operator!= (Pos& lhs, Pos& rhs) {
    return !(lhs.x == rhs.x && lhs.y == rhs.y);
}

class Node {
public:
    Pos state;
    Node* parent;
    string action;

    Node(Pos s, Node* p, string a) {
        state = s;
        parent = p;
        action = a;
    }

    friend bool operator== (Node& lhs, Node& rhs);
};

bool operator== (Node& lhs, Node& rhs) {
    return (lhs.state == rhs.state && lhs.parent == rhs.parent && lhs.action == rhs.action);
}

class StackFrontier {
private:
    vector<Node> frontier;
    int size = 0;

public:
    StackFrontier(int n) {
        frontier = vector<Node>(n, Node(createPos(-1, -1), nullptr, ""));
    }

    void add(Node node) {
        frontier[size].state = node.state;
        frontier[size].parent = node.parent;
        frontier[size].action = node.action;
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
            size--;
            return frontier[size];
        }
    }

    Pos createPos(int a, int b) {
        Pos pos;
        pos.setPos(a, b);
        return pos;
    }
};

class QueueFrontier {
private:
    vector<Node> frontier;
    int size = 0;

public:
    QueueFrontier(int n) {
        frontier = vector<Node>(n, Node(createPos(-1, -1), nullptr, ""));
    }

    void add(Node node) {
        frontier[size].state = node.state;
        frontier[size].parent = node.parent;
        frontier[size].action = node.action;
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

            vector<Node> new_frontier(frontier.size(), Node(createPos(-1, -1), nullptr, ""));

            for (int i = 1; i < frontier.size(); i++) {
                new_frontier[i - 1] = frontier[i];
            }

            frontier = new_frontier;

            size--;

            return r;
        }
    }

    Pos createPos(int a, int b) {
        Pos pos;
        pos.setPos(a, b);
        return pos;
    }
};

class Maze {
public:
    vector<vector<char>> maze;

    Pos start;
    Pos target;

    int height;
    int width;

    vector<string> solution_actions;
    vector<Pos> solution_cells;
    int solution_length;

    vector<Pos> explored;

    int neighbor_length;

    int num_explored;

    Maze(int w, int h) {
        maze = vector<vector<char>>(h);

        height = h;
        width = w;

        for (int i = 0; i < h; i++) {
            maze[i] = vector<char>(w);

            string tmp;

            getline(cin, tmp);

            for (int j = 0; j < w; j++) {
                maze[i][j] = tmp[j];

                if (tmp[j] == 'A') {
                    start.x = j;
                    start.y = i;
                }

                if (tmp[j] == 'B') {
                    target.x = j;
                    target.y = i;
                }
            }
        }
    }

    void print_maze() {
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                bool e = false;

                for (int k = 0; k < num_explored; k++) {
                    if (i == explored[k].y && j == explored[k].x) {
                        cout << "O ";
                        e = true;
                        break;
                    }
                }

                if (!e) {
                    cout << maze[i][j] << " ";
                }
            }
            cout << endl;
        }
    }

    Pos createPos(int a, int b) {
        Pos pos;
        pos.setPos(a, b);
        return pos;
    }

    vector<Pos> neighbors(Pos state) {
        int x = state.x;
        int y = state.y;
        Pos candidates[4] = {createPos(x - 1, y), createPos(x + 1, y), createPos(x, y + 1), createPos(x, y - 1)};

        vector<Pos> result(4);
        int size = 0;

        for (int i = 0; i < 4; i++) {
            if (0 <= candidates[i].x && candidates[i].x < width && 0 <= candidates[i].y && candidates[i].y < height && this->maze[candidates[i].y][candidates[i].x] != '#') {
                result[size] = candidates[i];
                size++;
            }
        }

        this->neighbor_length = size;

        return result;
    }

    void solve(int a) {
        num_explored = 0;

        Node start = Node(this->start, nullptr, "");
        if (a == 0) {
            QueueFrontier frontier = QueueFrontier(width * height);

            frontier.add(start);

            explored = vector<Pos>(width * height);

            while (true) {
                //print_maze();
                //cout << endl << endl;

                if (frontier.empty()) {
                    throw exception("no solution");
                }

                Node node = frontier.remove();
                explored[num_explored] = node.state;
                num_explored++;

                if (node.state == this->target) {
                    vector<string> actions(num_explored, "");
                    vector<Pos> cells(num_explored, createPos(-1, -1));
                    int size = 0;

                    while (node.parent != nullptr) {
                        actions[size] = node.action;
                        cells[size] = node.state;
                        node.state = node.parent->state;
                        node.action = node.parent->action;
                        node.parent = node.parent->parent;
                        size++;
                    }

                    vector<string> reversed_actions(size, "");
                    vector<Pos> reversed_cells(size, createPos(-1, -1));

                    for (int i = 0; i < size; i++) {
                        reversed_actions[i] = actions[size - i - 1];
                        reversed_cells[i] = cells[size - i - 1];
                    }

                    this->solution_actions = reversed_actions;
                    this->solution_cells = reversed_cells;
                    this->solution_length = size;

                    return;
                }

                vector<Pos> states = neighbors(node.state);

                for (int i = 0; i < this->neighbor_length; i++) {
                    if (!frontier.contains_state(states[i])) {
                        bool in_explored = false;

                        for (int j = 0; j < num_explored; j++) {
                            if (explored[j] == states[i]) {
                                in_explored = true;
                                break;
                            }
                        }

                        if (!in_explored) {
                            string action;

                            if (states[i].x - node.state.x > 0) {
                                action = "right";
                            } else if (states[i].x - node.state.x < 0) {
                                action = "left";
                            } else if (states[i].y - node.state.y > 0) {
                                action = "up";
                            } else if (states[i].y - node.state.y < 0) {
                                action = "down";
                            }

                            Node *p = new Node(node.state, node.parent, node.action);
                            Node child = Node(states[i], p, action);
                            frontier.add(child);
                        }
                    }
                }
            }
        }
        else {
            StackFrontier frontier = StackFrontier(width * height);

            frontier.add(start);

            explored = vector<Pos>(width * height);

            while (true) {
                //print_maze();
                //cout << endl << endl;

                if (frontier.empty()) {
                    throw exception("no solution");
                }

                Node node = frontier.remove();
                explored[num_explored] = node.state;
                num_explored++;

                if (node.state == this->target) {
                    vector<string> actions(num_explored, "");
                    vector<Pos> cells(num_explored, createPos(-1, -1));
                    int size = 0;

                    while (node.parent != nullptr) {
                        actions[size] = node.action;
                        cells[size] = node.state;
                        node.state = node.parent->state;
                        node.action = node.parent->action;
                        node.parent = node.parent->parent;
                        size++;
                    }

                    vector<string> reversed_actions(size, "");
                    vector<Pos> reversed_cells(size, createPos(-1, -1));

                    for (int i = 0; i < size; i++) {
                        reversed_actions[i] = actions[size - i - 1];
                        reversed_cells[i] = cells[size - i - 1];
                    }

                    this->solution_actions = reversed_actions;
                    this->solution_cells = reversed_cells;
                    this->solution_length = size;

                    return;
                }

                vector<Pos> states = neighbors(node.state);

                for (int i = 0; i < this->neighbor_length; i++) {
                    if (!frontier.contains_state(states[i])) {
                        bool in_explored = false;

                        for (int j = 0; j < num_explored; j++) {
                            if (explored[j] == states[i]) {
                                in_explored = true;
                                break;
                            }
                        }

                        if (!in_explored) {
                            string action;

                            if (states[i].x - node.state.x > 0) {
                                action = "right";
                            } else if (states[i].x - node.state.x < 0) {
                                action = "left";
                            } else if (states[i].y - node.state.y > 0) {
                                action = "up";
                            } else if (states[i].y - node.state.y < 0) {
                                action = "down";
                            }

                            Node *p = new Node(node.state, node.parent, node.action);
                            Node child = Node(states[i], p, action);
                            frontier.add(child);
                        }
                    }
                }
            }
        }
    }
};

int main() {
    cout << "Enter a maze with all walls as '#' and starting point A and target point B: " << endl;

    Maze maze = Maze(10, 10);

    string tmp;

    cout << endl << "Enter either 'DFS' or 'BFS' to search in either depth first search or breadth first search:" << endl;
    cin >> tmp;

    cout << endl << "Solving..." << endl << endl;

    if (tmp == "DFS") {
        maze.solve(1);
    }
    else if (tmp == "BFS") {
        maze.solve(0);
    }
    else {
        cout << "Invalid Input";
        return 1;
    }

    cout << "Cells explored: " << maze.num_explored << endl << endl;

    for (int i = 0; i < maze.solution_length; i++) {
        maze.maze[maze.solution_cells[i].y][maze.solution_cells[i].x] = 'O';
    }

    for (int i = 0; i < maze.height; i++) {
        for (int j = 0; j < maze.width; j++) {
            cout << maze.maze[i][j];
        }
        cout << endl;
    }

    cout << endl << "Shortest path: " << maze.solution_length << endl << endl;

    return 0;
}

/*
### #####B
### ####
##    ## #
## ## ##
#   # ###
# ###  ##
# #### ##
# #### ##
# ####
A ########
 */