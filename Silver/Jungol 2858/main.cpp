#include <iostream>
#include <string>

using namespace std;

int main() {
    int ans = 0;
    string s;

    cin >> s;

    int a, b;
    char prev = NULL;
    a = b = 0;

    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '(') {
            a++;
        } else if (s[i] == ')') {
            b++;
        }

        if (prev == '(' && s[i] == ')') {
            a--;
            b--;
            ans += (a - b);
        }

        prev = s[i];
    }

    cout << ans + a << endl;

    return 0;
}
