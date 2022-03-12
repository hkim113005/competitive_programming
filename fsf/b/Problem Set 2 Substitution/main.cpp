#include <stdio.h>
#include <string.h>
#include <iostream>

using namespace std;

bool key_verification(char key[50]) {
    char tmp[26];
    if (strlen(key) != 26) {
        return false;
    }
    for (int i = 0; i < 26; i++) {
        for (int j = 0; j < 26; j++) {
            if (tmp[j] == key[i]) {
                return false;
            }
        }
        tmp[i] = key[i];
    }
    return true;
}

string substitution(char plaintext[1000], string key) {
    string ciphertext = NULL;
    for (int i = 0; i < strlen(plaintext); i++) {
        if (65 <= plaintext[i] && plaintext[i] <= 90) {
            ciphertext[i] = key[plaintext[i] - 65];
        }
        else if (97 <= plaintext[i] && plaintext[i] <= 122) {
            ciphertext[i] = key[plaintext[i] - 97];
        }
        else {
            ciphertext[i] = plaintext[i];
        }
    }
    return ciphertext;
}

int main(int length, char *key[]) {
    char plaintext[1000];
    if (!key_verification(key[1])) {
        printf("Invalid Key!\n");
        return 1;
    }
    cin >> plaintext;
    cout << substitution(plaintext, key[1]);
    /*string key = get_string("");
    if (key_verification(key[1]))
    {
        printf("True");
    }
    else
    {
        printf("False");
    }
    printf("%s", key[1]);
    */
}