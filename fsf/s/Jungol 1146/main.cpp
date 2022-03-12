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
        int min = a[i - 1];
        int min_i = i - 1;

        for (int j = i; j < N; j++) {
            if (min > a[j]) {
                min = a[j];
                min_i = j;
            }
        }

        if (min_i != i - 1) {
            int tmp = a[i - 1];
            a[i - 1] = a[min_i];
            a[min_i] = tmp;
        }

        for (int j = 0; j < N; j++) {
            cout << a[j] << " ";
        }

        cout << endl;
    }

    return 0;
}
