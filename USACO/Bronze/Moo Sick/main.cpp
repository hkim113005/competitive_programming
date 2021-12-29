#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n, c, notes[20005], chord[15], chord_location[20000], cnt = 0;

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> notes[i];
    }

    cin >> c;

    for (int i = 0; i < c; i++) {
        cin >> chord[i];
    }

    sort(chord, chord + c);

    for (int i = 0; i <= n - c; i++) {
        int tmp[15];

        for (int j = i; j < i + c; j++) {
            tmp[j - i] = notes[j];
        }

        sort(tmp, tmp + c);

        bool is_chord = true;

        for (int j = 0; j < c - 1; j++) {
            if (chord[j] - tmp[j] != chord[j + 1] - tmp[j + 1]) {
                is_chord = false;
                break;
            }
        }

        if (is_chord) {
            chord_location[cnt] = i + 1;
            cnt++;
        }
    }

    cout << cnt << endl;

    for (int i = 0; i < cnt; i++) {
        cout << chord_location[i] << endl;
    }

    return 0;
}
