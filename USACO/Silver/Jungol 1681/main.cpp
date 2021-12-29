#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, min_cost = -1;
int prices[15][15];
bool check[15];

void process(int level, int cost, int cnt) {
    if (cnt == n) {
        cost += prices[level][0];

        if ((min_cost > cost || min_cost == -1) && prices[level][0] != 0) {
            min_cost = cost;
        }

        return;
    }

    for (int i = 0; i < n; i++) {
        if (check[i] && prices[level][i] != 0) {
            check[i] = false;
            process(i, cost + prices[level][i], cnt + 1);
            check[i] = true;
        }
    }
}

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        check[i] = true;

        for (int j = 0; j < n; j++) {
            cin >> prices[i][j];
        }
    }

    check[0] = false;

    process(0, 0, 1);

    cout << min_cost << endl;

    return 0;
}
