#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, min_cost = -1;
int prices[15][15];

void process(int level, int cost, vector<int> travelled, vector<bool> check) {
    travelled.push_back(level);
    check[level] = false;

    if (travelled.size() == n) {
        cost += prices[level][0];

        if ((min_cost > cost || min_cost == -1) && prices[level][0] != 0) {
            min_cost = cost;
        }

        return;
    }

    for (int i = 0; i < n; i++) {
        if (check[i] && prices[level][i] != 0) {
            process(i, cost + prices[level][i], travelled, check);
        }
    }
}

int main() {
    cin >> n;

    vector<bool> check(15);

    for (int i = 0; i < n; i++) {
        check[i] = true;

        for (int j = 0; j < n; j++) {
            cin >> prices[i][j];
        }
    }

    process(0, 0, vector<int>(0), check);

    cout << min_cost << endl;

    return 0;
}
