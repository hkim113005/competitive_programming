#include <iostream>
#include <string>

using namespace std;

int main() {
    string s;
    cin >> s;
    int cnt = 1;
    char prev = s[0];
    for (int i = 1; i < s.size(); i++) {
        if (s[i] == prev) cnt++;
        else {
            prev = s[i];
            cnt = 1;
        }
        if (cnt == 7) {
            cout << "YES" << endl;
            return 0;
        }
    }

    cout << "NO" << endl;
    return 0;
}
