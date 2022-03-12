#include <iostream>
#include <vector>

using namespace std;

int N;

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

int main() {
    cin >> N;

    vector<int> ans;
    vector<int> p;
    long long q = 1;

    for (int i = 1; i < N; i++) {
        if (gcd(i, N) == 1) {
            ans.push_back(i);
            q *= i;
            q %= N;
            p.push_back(q);
        }
    }

    while (p[p.size() - 1] != 1) {
        p.pop_back();
    }

    cout << p.size() << endl;
    for (int i = 0; i < p.size(); i++) {
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}
