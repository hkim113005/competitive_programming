#include <iostream>

using namespace std;

int main() {
    string words[5];

    for (int i = 0; i < 5; i++) {
        cin >> words[i];
    }

    int x = 0;
    while (true) {
        bool b = true;

        for (int i = 0; i < 5; i++) {
            if (x < words[i].length()) {
                cout << words[i][x];
                b = false;
            }
        }

        x++;

        if (b) {
            break;
        }
    }

    return 0;
}
