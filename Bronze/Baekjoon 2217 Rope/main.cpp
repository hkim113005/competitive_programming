#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, max_w = 0;
vector<int> ropes;

int main() {
    cin >> n;

    ropes.resize(n);

    for (int i = 0; i < n; i++) {
        cin >> ropes[i];
    }

    sort(ropes.begin(), ropes.end());

    for (int i = 0; i < n; i++) {
        if (ropes[i] * (n - i) > max_w) {
            max_w = ropes[i] * (n - i);
        }
    }

    cout << max_w;

    return 0;
}
