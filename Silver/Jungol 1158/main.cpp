#include <iostream>

using namespace std;

int main() {
    int N;
    int a[105];

    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }

    for (int i = 1; i < N; i++) {
        int c = a[i];

        for (int j = 0; j < i; j++) {
            if (c < a[j]) {
                for (int k = i; k > j; k--) {
                    a[k] = a[k - 1];
                }

                a[j] = c;

                break;
            }
        }

        for (int j = 0; j < N; j++) {
            cout << a[j] << ' ';
        }

        cout << endl;
    }

    return 0;
}
