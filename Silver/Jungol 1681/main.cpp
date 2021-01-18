#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, min_cost = -1;
int prices[15][15];

void process(int level, int cost, vector<int> travelled) {
    travelled.push_back(level);

    if (travelled.size() == n) {
        cost += prices[level][0];

        if ((min_cost > cost || min_cost == -1) && prices[level][0] != 0) {
            min_cost = cost;
        }

        return;
    }

    for (int i = 0; i < n; i++) {
        if (count(travelled.begin(), travelled.end(), i) == 0 && prices[level][i] != 0) {
            process(i, cost + prices[level][i], travelled);
        }
    }
}

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> prices[i][j];
        }
    }

    process(0, 0, vector<int>(0));

    cout << min_cost << endl;

    return 0;
}
