#include <iostream>

using namespace std;

int main() {
    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;

        int ans = 0;
        for (int j = 1; j * j <= x; j++) {
            if (x % j == 0) ans += (x == j * j ? 1 : 2);
        }

        cout << ans << endl;
    }

    return 0;
}
