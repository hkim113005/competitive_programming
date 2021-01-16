#include <iostream>

using namespace std;

int n, cnt = 0, coins[6] = { 500, 100, 50, 10, 5, 1 };

int main() {
    cin >> n;

    n = 1000 - n;

    for (int & coin : coins) {
        cnt += n / coin;
        n -= n / coin * coin;
    }

    cout << cnt;

    return 0;
}
