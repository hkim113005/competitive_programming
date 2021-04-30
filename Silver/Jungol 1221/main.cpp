#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;

    cin >> N;

    vector<int> s;

    for (int i = 0; i < N; i++) {
        char t;

        cin >> t;

        if ('0' <= t && t <= '9') {
            s.emplace_back(t - '0');
        } else {
            int a, b;

            if (t == '*') {
                a = s[s.size() - 2];
                b = s[s.size() - 1];

                s[s.size() - 2] = a * b;

                s.pop_back();
            } else if (t == '/') {
                a = s[s.size() - 2];
                b = s[s.size() - 1];

                if (a == 0 || b == 0) {
                    s[s.size() - 2] = 0;
                }
                else {
                    s[s.size() - 2] = a / b;
                }

                s.pop_back();
            } else if (t == '+') {
                a = s[s.size() - 2];
                b = s[s.size() - 1];

                s[s.size() - 2] = a + b;

                s.pop_back();
            } else if (t == '-') {
                a = s[s.size() - 2];
                b = s[s.size() - 1];

                s[s.size() - 2] = a - b;

                s.pop_back();
            }
        }
    }

    cout << s[0];

    return 0;
}