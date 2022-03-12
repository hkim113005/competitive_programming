#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int cnt = 0;

void process(string word) {
    if (word.length() == 2) {
        return;
    }

    if (word.length() % 2 == 0) {
        return;
    }
    else {
        string first_half = word.substr(0, word.length() / 2);
        string second_half = word.substr(word.length() / 2, word.length() / 2 + 1);

        if (first_half == second_half.substr(0, first_half.length())) {
            cnt++;
            process(second_half);
        }
        if (first_half == second_half.substr(1, first_half.length())) {
            cnt++;
            process(second_half);
        }

        first_half = word.substr(0, word.length() / 2 + 1);
        second_half = word.substr(word.length() / 2 + 1, word.length() / 2);

        if (second_half == first_half.substr(0, second_half.length())) {
            cnt++;
            process(first_half);
        }
        if (second_half == first_half.substr(1, second_half.length())) {
            cnt++;
            process(first_half);
        }
    }
}

int main() {
    //freopen("scode.in", "r", stdin);
    //freopen("scode.out", "w", stdout);

    string word;

    cin >> word;

    process(word);

    cout << cnt;

    return 0;
}
