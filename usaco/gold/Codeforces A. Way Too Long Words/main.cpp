#include <iostream>
#include <string>

using namespace std;

int main() {
    int N;

    cin >> N;

    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        if (s.size() > 10) {
            cout << s[0];
            cout << s.size() - 2;
            cout << s[s.size() - 1] << endl;
        }
        else {
            cout << s << endl;
        }
    }

    return 0;
}
