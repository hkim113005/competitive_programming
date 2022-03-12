#include <iostream>

using namespace std;

int t;
string s;

void solve() {
    cin >> s;
    int r, g, b, R, G, B;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == 'r') r = i;
        if (s[i] == 'b') g = i;
        if (s[i] == 'g') b = i;
        if (s[i] == 'R') R = i;
        if (s[i] == 'B') G = i;
        if (s[i] == 'G') B = i;
    }

    if (r < R && g < G && b < B) {
        cout << "YES" << endl;
    }
    else {
        cout << "NO" << endl;
    }
}

int main() {
    cin >> t;
    while (t--) solve();

    return 0;
}
