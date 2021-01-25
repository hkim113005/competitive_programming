#include <iostream>
#include <string>
#include <string.h>
#include <vector>

using namespace std;

int N, Q;
string d;

int process(string target) {
    int brush = 0;

    for (int i = 'Z'; i >= 'A'; i--) {
        vector<int> paint;

        for (int j = 0; j < target.length(); j++) {
            if (target[j] == i) {
                paint.push_back(j);
            }
        }

        brush += paint.size();
        int ps = paint.size();

        for (int j = 0; j < ps - 1; j++) {
            if (paint[j] + 1 == paint[j + 1]) {
                brush--;
            }
            else {
                int chk = 0;

                for (int k = paint[j] + 1; k < paint[j + 1]; k++) {
                    if (target[k] < i) {
                        chk = 1;
                        break;
                    }

                    if (target[k] == '.') {
                        chk = 1;
                        break;
                    }
                }

                if (chk == 0) {
                    brush--;
                }
            }
        }
    }

    return brush;
}

int main() {
    cin >> N >> Q >> d;

    for (int i = 0; i < Q; i++) {
        int a, b;

        cin >> a >> b;

        string t = d;

        for (int j = a - 1; j <= b - 1; j++) {
            t[j] = '.';
        }

        cout << process(t) << endl;
    }

    return 0;
}
