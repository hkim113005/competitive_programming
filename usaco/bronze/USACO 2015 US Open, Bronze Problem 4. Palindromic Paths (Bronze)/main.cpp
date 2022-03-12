#include <iostream>
#include <string.h>
#include <stdio.h>
#include <fstream>

using namespace std;

int n, words_len = 0;

char a[1000][1000];

typedef struct node {
    char word[100];
} node;

node words[1000];

bool inWords(char *word) {
    for (int i = 0; i < words_len; i++) {
        if (strcmp(word, words[i].word) == 0) {
            return true;
        }
    }
    return false;
}

void addWord(char *word) {
    strcpy(words[words_len].word, word);
    words_len++;
}

bool process(int x, int y, char word[1000]) {
    if (x == n - 1 && y == n - 1) {
        char str[2];
        str[0] = a[x][y];
        str[1] = NULL;
        strcat(word, str);

        if (!inWords(word)) {
            addWord(word);
        }

        return false;
    }
    else if (x == n) {
        return true;
    }
    else if (y == n) {
        return true;
    }

    char str[2];
    str[0] = a[x][y];
    str[1] = NULL;
    strcat(word, str);

    if (!process(x + 1, y, word)) {
        word[strlen(word) - 1] = NULL;
    }

    bool r = process(x, y + 1, word);
    word[strlen(word) - 1] = NULL;
    return r;
}

bool checkPalindrome(char *word) {
    for(int i = 0; i < words_len; i++) {
        if (word[i] != word[words_len - i - 1]) {
            return false;
        }
    }
    return true;
}

int main() {
    freopen("palpath.in", "r", stdin);
    freopen("palpath.out", "w", stdout);

    int cnt = 0;

    scanf("%i", &n);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%c", &a[i][j]);

            if (a[i][j] == 10) {
                scanf("%c", &a[i][j]);
            }
        }
    }

    char word[100];

    for (int i = 0; i < 100; i++) {
        word[i] = NULL;
    }

    process(0, 0, word);

    /*
    for (int i = 0; i < words_len; i++) {
        printf("%s\n", words[i].word);
    }
    */

    for (int i = 0; i < words_len; i++) {
        if (checkPalindrome(words[i].word)) {
            cnt++;
        }
    }

    printf("%i", cnt);

    return 0;
}
