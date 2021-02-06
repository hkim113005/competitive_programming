#include <iostream>

using namespace std;

int main() {
    int n, o = 0, e = 0;

    cin >> n;

    for (int i = 0; i < n; i++) {
        int tmp;

        cin >> tmp;

        if (tmp % 2 == 0) {
            e++;
        }
        else {
            o++;
        }
    }

    while (e < o) {
        e++;
        o -= 2;
    }

    while (e > o + 1) {
        e--;
    }

    cout << e + o;

    return 0;
}
