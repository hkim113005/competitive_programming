#include <iostream>
#include <set>

using namespace std;

int N;
int p[100005];
int k;

class BIT {
public:
    int a[100005];

    void update(int x, int i) {
        while (i <= N) {
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
    freopen("sleepy.in", "r", stdin);
    freopen("sleepy.out", "w", stdout);

    BIT bit;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> p[i];
        bit.a[p[i]] = 0;
    }
    for (int i = N - 1; i > 0; i--) {
        if (p[i] > p[i - 1]) continue;
        else {
            k = i;
            break;
        }
    }
    for (int i = k; i < N; i++) {
        bit.update(1, p[i]);
    }

    cout << k << endl;
    for (int i = 0; i < k; i++) {
        int d = bit.query(p[i]);
        bit.update(1, p[i]);
        //cout << d << ": ";
        cout << k - i + d - 1;
        if (i < k - 1) cout << " ";
    }
    cout << endl;

    return 0;
}
