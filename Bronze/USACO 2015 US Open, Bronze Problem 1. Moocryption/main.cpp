#include <iostream>
#include <stdio.h>
#include <fstream>

int main() {
    freopen("moocrypt.in", "r", stdin);
    freopen("moocrypt.out", "w", stdout);
    int n, m, max = 0;
    char board[55][55];
    scanf("%i %i", &n, &m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%c", &board[i][j]);
            if (board[i][j] == 10) {
                scanf("%c", &board[i][j]);
            }
        }
    }
    for (int k = 'A'; k <= 'Z'; k++) {
        for (int l = 'A'; l <= 'Z'; l++) {
            int cnt = 0;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if (i < 2 && j < 2) {
                        if (board[i][j] == k && board[i + 1][j + 1] == l && board[i + 2][j + 2] == l) {
                            cnt++;
                        }
                    }
                    else if (i > n - 2 && j > n - 2) {
                        if (board[i][j] == k && board[i - 1][j - 1] == l && board[i - 2][j - 2] == l) {
                            cnt++;
                        }
                    }
                    else {
                        if (board[i][j] == k && board[i + 1][j + 1] == l && board[i + 2][j + 2] == l) {
                            cnt++;
                        }
                        if (board[i][j] == k && board[i - 1][j - 1] == l && board[i - 2][j - 2] == l) {
                            cnt++;
                        }
                    }
                    if (i < 2 && j < n - 2) {
                        if (board[i][j] == k && board[i + 1][j - 1] == l && board[i + 2][j - 2] == l) {
                            cnt++;
                        }
                    }
                    else if (i > n - 2 && j > n) {
                        if (board[i][j] == k && board[i - 1][j + 1] == l && board[i - 2][j + 2] == l) {
                            cnt++;
                        }
                    }
                    else {
                        if (board[i][j] == k && board[i + 1][j - 1] == l && board[i + 2][j - 2] == l) {
                            cnt++;
                        }
                        if (board[i][j] == k && board[i - 1][j + 1] == l && board[i - 2][j + 2] == l) {
                            cnt++;
                        }
                    }
                    if (j < 2) {
                        if (board[i][j] == k && board[i][j + 1] == l && board[i][j + 2] == l) {
                            cnt++;
                        }
                    }
                    else if (j > n - 2) {
                        if (board[i][j] == k && board[i][j - 1] == l && board[i][j - 2] == l) {
                            cnt++;
                        }
                    }
                    else {
                        if (board[i][j] == k && board[i][j + 1] == l && board[i][j + 2] == l) {
                            cnt++;
                        }
                        if (board[i][j] == k && board[i][j - 1] == l && board[i][j - 2] == l) {
                            cnt++;
                        }
                    }
                    if (i < 2) {
                        if (board[i][j] == k && board[i + 1][j] == l && board[i + 2][j] == l) {
                            cnt++;
                        }
                    }
                    else if (i > n - 2) {
                        if (board[i][j] == k && board[i - 1][j] == l && board[i - 2][j] == l) {
                            cnt++;
                        }
                    }
                    else {
                        if (board[i][j] == k && board[i + 1][j] == l && board[i + 2][j] == l) {
                            cnt++;
                        }
                        if (board[i][j] == k && board[i - 1][j] == l && board[i - 2][j] == l) {
                            cnt++;
                        }
                    }
                }
            }
            if (cnt > max) {
                max = cnt;
            }
        }
    }
    printf("%i\n", max);
}
