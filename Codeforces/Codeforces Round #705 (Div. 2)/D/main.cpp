#include <iostream>

using namespace std;

int gcd(int a, int b) {
    if (b == 0)
        return a;

    return gcd(b, a % b);
}

int main() {
    int N, Q;
    int a[200005];

    cin >> N >> Q;

    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }



    return 0;
}
