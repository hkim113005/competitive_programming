#include <iostream>

using namespace std;

int main() {
    int ans = 0;
    string s;

    cin >> s;

    int x = 0, y = 0;

    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '(' && s[i + 1] == ')') {
            ans += x + y;
            y = 0;
            i++;
            continue;
        } else if (s[i] == '(') {
            x++;
        } else if (s[i] == ')') {
            x--;
            y++;
        }
    }

    cout << ans + y;

    return 0;
}
