#include <iostream>

using namespace std;

int N;
char map[10000][10000];

int main() {
    cin >> N;

    for (int i = 0; i < N; i++) {
        string s;

        cin >> s;

        int x = 100;
        int y = 100;

        for (int j = 0; j < s.length(); j++) {
            map[x][y] = s[j];

            if (s[j] == 'W') {
                map[]
            }
        }
    }

    return 0;
}
