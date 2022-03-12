#include <stdio.h>
#include <iostream>

int n = 0;
char N, pyramid[9][20];

using namespace std;

void input() { // Takes in only a input between 1 and 8, including.
    while (1) {
        cin >> N;
        if (49 <= N && N <= 57) {
            n = N - 48;
            break;
        }
    }
}

void creating_pyramid() { // Creates the pyramid shape in side 2D array pyramid.
    for (int i = 1; i <= n; i++) { // Going through every row.
        for (int j = 0; j < n - i; j++) {// Adding spaces.
            pyramid[i - 1][j] = ' ';
        }
        for (int j = n - i; j < n; j++) {// Adding left #'s.
            pyramid[i - 1][j] = '#';
        }
        for (int j = n + 1; j < n + 2; j++) {// Adding 2 # gap.
            pyramid[i - 1][j] = ' ';
        }
        for (int j = n + 2; j < n + 2 + i; j++) {// Adding right #'s.
            pyramid[i - 1][j] = '#';
        }
        /*
        for (int j = n + 2 + i; j < 2 * n + 2; j++) {// Adding spaces.
            pyramid[i - 1][j] = ' ';
        }
        */
    }
}

void output() { // Prints the 2D array pyramid.
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 2 * n + 3; j++) {
            printf("%c", pyramid[i][j]);
        }
        printf("\n");
    }
}

int main() {
    input();
    creating_pyramid();
    output();
}