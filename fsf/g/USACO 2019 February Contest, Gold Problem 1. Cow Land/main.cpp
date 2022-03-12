#include <iostream>

using namespace std;

int N, Q;
int e[100005];

int main() {
    cin >> N >> Q;
    for (int i = 0; i < N; i++) {
        cin >> e[i];
    }
    for (int i = 0; i < N - 1; i++) {
        int a, b;
        cin >> a >> b;
    }

    return 0;
}
