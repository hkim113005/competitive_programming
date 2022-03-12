#include <iostream>
#include <math.h>

using namespace std;

void solve() {
    double U, V, A, S;

    cin >> U >> V >> A >> S;

    if (U == V) {
        cout << "Yes" << endl;
        return;
    }

    double a = U * U - 2 * A * S;

    if (a < 0) {
        cout << "Yes" << endl;
        return;
    }

    a = sqrt(a);

    if (a <= V) {
        cout << "Yes" << endl;
        return;
    }

    cout << "No" << endl;
}

int main() {
    int T;

    cin >> T;

    while (T--) {
        solve();
    }

    return 0;
}
