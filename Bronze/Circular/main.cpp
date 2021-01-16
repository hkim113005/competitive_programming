#include <iostream>

using namespace std;

typedef struct node{
    int value = 0;
    int* left;
    int* right;
} node;

node circle[2000000];

int main() {
    int n, m = 0;

    cin >> n;

    for (int i = 0; i < n; i++) {
        int tmp;

        cin >> tmp;

        if (m == 0) {
            circle[m].value += tmp;

            m++;
        }
        else {
            if ((circle[m - 1].value >= 0 && tmp >= 0) || (circle[m - 1].value < 0 && tmp < 0)) {
                circle[m - 1].value += tmp;
            }
            else {
                circle[m].value += tmp;
                circle[m - 1].right = &circle[m].value;
                circle[m].left = &circle[m - 1].value;
                m++;
            }
        }
    }

    circle[0].left = &circle[m - 1].value;
    circle[m - 1].right = &circle[0].value;

    printf("HELLO");

    return 0;
}
