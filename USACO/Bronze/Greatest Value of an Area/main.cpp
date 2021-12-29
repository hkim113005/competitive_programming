#include <iostream>

using namespace std;

typedef struct node {
    int value;
    int index;
} node;

node s[50005];

int main() {
    int n, q;

    cin >> n >> q;

    for (int i = 0; i < n; i++) {
        cin >> s[i].value;
        s[i].index = i;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - 1; j++) {
            if (s[j].value < s[j + 1].value) {
                int tmp = s[j].value;
                s[j].value = s[j + 1].value;
                s[j + 1].value = tmp;

                tmp = s[j].index;
                s[j].index = s[j + 1].index;
                s[j + 1].index = tmp;
            }
        }
    }

    for (int i = 0; i < q; i++) {
        int a, b;

        cin >> a >> b;

        for (int j = 0; j < n; j++) {
            if (a - 1 <= s[j].index && s[j].index <= b - 1) {
                cout << s[j].value << endl;
                break;
            }
        }
    }
    return 0;
}
