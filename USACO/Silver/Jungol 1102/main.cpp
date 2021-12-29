#include <iostream>

using namespace std;

int main() {
    int N;
    int a[105], b = 0;

    cin >> N;

    for (int i = 0; i < N; i++) {
        char t;

        cin >> t;

        if (t == 'i') {
            cin >> a[b];
            b++;
        }
        else if (t == 'o') {
            if (b == 0) {
                cout << "empty" << endl;
            }
            else {
                cout << a[b - 1] << endl;
                b--;
            }
        }
        else if (t == 'c') {
            cout << b << endl;
        }
    }

    return 0;
}
