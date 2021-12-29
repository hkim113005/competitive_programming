#include <iostream>

using namespace std;

string in;

string solve(int i) {
    string t = "";

    if (in[i] == ')') {
        return "";
    }

    if (in[i + 1] == '(') {
        for (int j = 0; j < in[i] - '0'; j++) {
            t += solve(i + 2);
        }

        return t;
    }

    return in[i] + solve(i + 1);
}

int main() {
    cin >> in;

    cout << solve(0);

    return 0;
}
