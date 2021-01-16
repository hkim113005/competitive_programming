#include <iostream>
#include <math.h>

using namespace std;

int n, m, o1, o2, ans = 0;

int main() {
    cin >> n >> o1 >> o2;

    cin >> m;

    for (int i = 0; i < m; i++) {
        int tmp;

        cin >> tmp;

        if (!(o1 == tmp || o2 == tmp)) {
            if (abs(tmp - o1) > abs(tmp - o2)) {
                ans += abs(tmp - o2);
                o2 = tmp;
            }
            else {
                ans += abs(tmp - o1);
                o1 = tmp;
            }
        }
    }

    cout << ans << endl;

    return 0;
}
