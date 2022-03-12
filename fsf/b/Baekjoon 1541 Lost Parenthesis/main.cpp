#include <iostream>
#include <string>

using namespace std;

int ans = 0;
string s;

int main() {
    int num = 0;
    bool minus = false;

    cin >> s;

    for (auto c:s) {
        if (c == '+' || c == '-') {
            if (minus) {
                ans -= num;
            }
            else {
                ans += num;

                if (c == '-') {
                    minus = true;
                }
            }
            num = 0;
        }
        else {
            num = num * 10 + c - '0';
        }
    }

    if (minus) {
        ans -= num;
    }
    else {
        ans += num;
    }

    cout << ans;

    return 0;
}
