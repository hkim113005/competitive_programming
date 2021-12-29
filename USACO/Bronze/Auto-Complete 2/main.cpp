#include <iostream>
#include <algorithm>
#include <fstream>

using namespace std;

typedef struct node {
    string word;
    int index = -2;
} node;

node dict[1010000];

int main() {
    freopen("auto.in", "r", stdin);
    freopen("auto.out", "w", stdout);

    int W, N;

    cin >> W >> N;

    for (int i = 0; i < W; i++) {
        cin >> dict[i].word;
        dict[i].index = i;
    }

    for (int i = 0; i < W; i++) {
        for (int j = 0; j < W - 1; j++) {
            if (dict[j].word > dict[j + 1].word) {
                string tmp = dict[j].word;
                dict[j].word = dict[j + 1].word;
                dict[j + 1].word = tmp;

                int tmp1 = dict[j].index;
                dict[j].index = dict[j + 1].index;
                dict[j + 1].index = tmp1;
            }
        }
    }

    for (int i = 0; i < N; i++) {
        int k, ans = -1;
        string word;

        cin >> k >> word;

        for (int j = 0; j < W; j++) {
            if (word.length() <= dict[j].word.length()) {
                if (word == dict[j].word.substr(0, word.length())) {
                    ans = dict[j + k - 1].index;
                    break;
                }
            }
        }

        cout << ans + 1 << endl;
    }

    return 0;
}
