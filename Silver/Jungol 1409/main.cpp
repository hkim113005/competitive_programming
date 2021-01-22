#include <iostream>

using namespace std;

int n, m, doors[50], ans = 1000000000;

void door(int open1, int open2, int index, int total) {
    int cost = 0;

    if (index == m) {
        ans = min(ans, total);
        return;
    }

    cost = abs(doors[index] - open1);
    door(doors[index], open2, index + 1, total + cost);

    cost = abs(doors[index] - open2);
    door(open1, doors[index], index + 1, total + cost);
}

int main() {
    int open1, open2;

    cin >> n >> open1 >> open2 >> m;

    for (int i = 0; i < m; i++) {
        cin >> doors[i];
    }

    door(open1, open2, 0, 0);

    cout << ans;

    return 0;
}
