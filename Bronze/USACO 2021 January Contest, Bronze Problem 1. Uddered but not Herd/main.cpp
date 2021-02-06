#include <iostream>
#include <string>

using namespace std;

int main() {
    int ans = 0;

    string alphabet;

    cin >> alphabet;

    string word;

    cin >> word;

    for (int i = 0; i < word.length();) {
        for (int j = 0; j < alphabet.length(); j++) {
            char d1 = word[i];
            char d2 = alphabet[j];

            if (word[i] == alphabet[j]) {
                i++;
            }
        }

        ans++;
    }

    cout << ans;

    return 0;
}
