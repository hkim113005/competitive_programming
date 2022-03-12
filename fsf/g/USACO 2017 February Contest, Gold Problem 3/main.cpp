#include <algorithm>
#include <iostream>
#include <stdio.h>

#define f first
#define s second

using namespace std;

int N;
pair<int, int> b[100005];

class BIT {
public:
    int a[100005];

    void update(int x, int i) {
        while (i < 2 * N) {
            a[i] += x;
            i += (i & (-i));
        }
    }

    int query(int i) {
        int sum = 0;
        while (i > 0) {
            sum += a[i];
            i -= (i & (-i));
        }
        return sum;
    }

    int query(int l, int r) {
        return query(r) - query(l);
    }
};

int main() {
    freopen("circlecross.in", "r", stdin);
    freopen("circlecross.out", "w", stdout);

    BIT bit;
    cin >> N;

    for (int i = 0; i < N; i++) {
        b[i].f = b[i].s = -1;
    }

    for (int i = 0; i < 2 * N; i++) {
        int tmp;
        cin >> tmp;
        tmp--;

        if (b[tmp].f == -1) b[tmp].f = i;
        else b[tmp].s = i;

        bit.a[i] = 0;
    }

    sort(b, b + N);

    int ans = 0;
    for (int i = 0; i < N; i++) {
        ans += bit.query(b[i].f, b[i].s);
        bit.update(1, b[i].s);
    }

    cout << ans;

    return 0;
}
