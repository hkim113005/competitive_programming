#include <iostream>

using namespace std;

int main() {
    int N;

    cin >> N;

    if (N <= 2) {
        cout << "NO";
        return 0;
    }

    if (N % 2 == 0) {
        cout << "YES";
        return 0;
    }

    cout << "NO";
    return 0;
}
