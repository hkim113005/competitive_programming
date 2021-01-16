#include <iostream>

using namespace std;

int main() {
    long long C = 0;
    long long O = 0;
    long long ans = 0;
    int n;
    string s;

    cin >> n >> s;

    for (int i = 0; i < n; i++) {
        if (s[i] == 'C') {
            C++;
        }
        else if (s[i] == 'O') {
            O += C;
        }
        else {
            ans += O;
        }
    }

    cout << ans << endl;

    return 0;
}
