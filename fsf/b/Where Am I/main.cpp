#include <iostream>
#include <string.h>
#include <stdio.h>
#include <fstream>
#include <string>

using namespace std;

int n;
char m[100];

bool same(int a, int b, int c, int d) {
    char tmp1[100];

    for (int i = 0; i < 100; i++) {
        tmp1[i] = ' ';
    }

    for (int i = a; i < b; i++) {
        tmp1[i - a] = m[i];
    }

    char tmp2[100];

    for (int i = 0; i < 100; i++) {
        tmp2[i] = ' ';
    }

    for (int i = c; i < d; i++) {
        tmp2[i - c] = m[i];
    }

    if (strcmp(tmp1, tmp2) == 0) {
        return true;
    }
    else {
        return false;
    }
}

int main() {
    freopen("whereami.in", "r", stdin);
    freopen("whereami.out", "w", stdout);
    int n;
    cin >> n;
    scanf("%s", m);
    for(int guess = 1; guess <= n; guess++) {
        bool good = true;
        for(int i = 0; i + guess <= n; i++) {
            for(int j = 0; j < i; j++) {
                if(same(i, i + guess, j, j + guess)) {
                    good = false;
                }
            }
        }
        if(good) {
            cout << guess << "\n";
            break;
        }
    }
}
