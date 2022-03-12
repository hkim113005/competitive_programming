#include <iostream>
#include <string.h>
#include <string>

using namespace std;

typedef struct node {
    string word;
    int cnt = 0;
} node;

node words[1000];
int words_len = 0;

int main() {
    //freopen("input.in", "r", stdin);
    //freopen("output.out", "w", stdout);

    string sentence;
    string word;

    while (true) {
        bool end = false;

        getline(cin, sentence);

        word = "";

        for (int x = 0; x <= sentence.length(); x++) {
            if (sentence[x] == ' ' || sentence[x] == '\0') {
                bool first = true;

                for (int i = 0; i < words_len; i++) {
                    if (words[i].word == word) {
                        first = false;
                        words[i].cnt++;

                        break;
                    }
                }

                if (first) {
                    words[words_len].word = word;
                    words[words_len].cnt++;
                    words_len++;
                }

                word = "";
            }
            else {
                word += sentence[x];
            }

            if (word == "END") {
                end = true;

                break;
            }
        }

        if (end) {
            break;
        }

        for (int i = 0; i < words_len; i++) {
            for (int j = 0; j < words_len - 1; j++) {
                if (words[j].word > words[j + 1].word) {
                    string tmp = words[j].word;
                    words[j].word = words[j + 1].word;
                    words[j + 1].word = tmp;

                    int t = words[j].cnt;
                    words[j].cnt = words[j + 1].cnt;
                    words[j + 1].cnt = t;
                }
            }
        }

        for (int i = 0; i < words_len; i++) {
            cout << words[i].word << " : " << words[i].cnt << endl;

            words[i].word = "";
            words[i].cnt = 0;
        }

        words_len = 0;
    }

    return 0;
}
