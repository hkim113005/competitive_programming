#include <iostream>
#include <queue>

using namespace std;

int N;

class BIT {
public:
    int b[100005];

    void update(int x, int i) {
        i++;
        while (i <= N) {
            b[i] += x;
            i += (i & (-i));
        }
    }

    int query(int i) {
        i++;
        int sum = 0;
        while (i > 0) {
            sum += b[i];
            i -= (i & (-i));
        }
        return sum;
    }
};

priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> A;
int a[100005];
BIT bit;

int main() {
    freopen("sort.in", "r", stdin);
    freopen("sort.out", "w", stdout);

    cin >> N;
    for (int i = 0; i < N; i++) {
        int idx = i, tmp;
        cin >> tmp;
        A.push(make_pair(tmp, idx));
        bit.b[i] = 0;
    }

    int tmp = 0;
    while (!A.empty()) {
        pair<int, int> f = A.top();
        A.pop();
        //cout << f.first << " " << f.second << endl;
        a[f.second] = tmp;
        tmp++;
    }

    int ans = 1;
    for (int i = 0; i < N - 1; i++) {
        int l;
        bit.update(1, a[i]);
        l = i + 1 - bit.query(i);
        ans = max(l, ans);
        //cout << l << endl;
    }

    cout << ans << endl;

    return 0;
}
