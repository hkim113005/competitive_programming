#include <iostream>

using namespace std;

int cups[4] = {1, 2, 3, 4};
string s;

int main() {
    cin >> s;

    for (int i = 0; i < s.length(); i++) {
        if (s[i] == 'A') {
            swap(cups[0], cups[1]);
        }
        else if (s[i] == 'B') {
            swap(cups[0], cups[2]);
        }
        else if (s[i] == 'C') {
            swap(cups[0], cups[3]);
        }
        else if (s[i] == 'D') {
            swap(cups[1], cups[2]);
        }
        else if (s[i] == 'E') {
            swap(cups[1], cups[3]);
        }
        else if (s[i] == 'F') {
            swap(cups[2], cups[3]);
        }
    }

    for (int i = 0; i < 4; i++) {
        if (cups[i] == 1) {
            cout << i + 1;
        }
    }

    cout << endl;

    for (int i = 0; i < 4; i++) {
        if (cups[i] == 4) {
            cout << i + 1;
        }
    }

    return 0;
}
