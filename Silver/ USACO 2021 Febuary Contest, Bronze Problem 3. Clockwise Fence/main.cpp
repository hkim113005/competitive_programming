#include <iostream>

using namespace std;

int N;

int main() {
    cin >> N;

    for (int i = 0; i < N; i++) {
        string s;

        cin >> s;

        int cw = 0;
        int ccw = 0;

        for (int j = 0; j < s.length() - 1; j++) {
            string t;
            t += s[j];
            t += s[j + 1];

            if (t == "NW" || t == "WN") {
                ccw++;
            }
            else if (t == "SE" || t == "ES") {
                ccw++;
            }
            else if (t == "SW" || t == "WS") {
                cw++;
            }
            else if (t == "NE" || t == "EN") {
                cw++;
            }
        }

        if (cw > ccw) {
            cout << "CW" << endl;
        }
        else {
            cout << "CCW" << endl;
        }
    }

    return 0;
}
