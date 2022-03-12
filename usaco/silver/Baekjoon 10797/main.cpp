#include <iostream>

using namespace std;

int main() {
    int N, ans = 0;

    cin >> N;

    for (int i = 0; i < 5; i++) {
        int tmp;

        cin >> tmp;

        if (tmp == N) ans++;
    }

    cout << ans;

    return 0;
}
