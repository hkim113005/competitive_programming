#include <iostream>

int main() {
    int n, m, cnt = 0, max = 0;
    char farm[750][750];
    bool e = false;

    scanf("%d %d", &m, &n);

    for (int i = 0; i < n; i++) {
        scanf("%s", farm[i]);
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (farm[i][j] == '.') {
                farm[i][j] = '#';
                e = true;
                break;
            }
        }

        if (e) {
            break;
        }
    }

    if (e) {
        cnt = 1;

        while (true) {
            for (int k = 0; k < 3; k++) {
                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < m; j++) {
                        if (i > 0) {
                            if (farm[i - 1][j] == '#' && farm[i][j] == '.') {
                                farm[i][j] = '#';
                                cnt++;
                            }
                        }
                        if (i < n - 1) {
                            if (farm[i + 1][j] == '#' && farm[i][j] == '.') {
                                farm[i][j] = '#';
                                cnt++;
                            }
                        }
                        if (j > 0) {
                            if (farm[i][j - 1] == '#' && farm[i][j] == '.') {
                                farm[i][j] = '#';
                                cnt++;
                            }
                        }
                        if (j < m - 1) {
                            if (farm[i][j + 1] == '#' && farm[i][j] == '.') {
                                farm[i][j] = '#';
                                cnt++;
                            }
                        }
                        if (i > 0 && j > 0) {
                            if (farm[i - 1][j - 1] == '#' && farm[i][j] == '.') {
                                farm[i][j] = '#';
                                cnt++;
                            }
                        }
                        if (i > 0 && j < m - 1) {
                            if (farm[i - 1][j + 1] == '#' && farm[i][j] == '.') {
                                farm[i][j] = '#';
                                cnt++;
                            }
                        }

                        if (i < n - 1 && j > 0) {
                            if (farm[i + 1][j - 1] == '#' && farm[i][j] == '.') {
                                farm[i][j] = '#';
                                cnt++;
                            }
                        }
                        if (i < n - 1 && j < m - 1) {
                            if (farm[i + 1][j + 1] == '#' && farm[i][j] == '.') {
                                farm[i][j] = '#';
                                cnt++;
                            }
                        }
                    }
                }

                for (int i = 0; i < n; i++) {
                    for (int j = m - 1; j >= 0; j--) {
                        if (i > 0) {
                            if (farm[i - 1][j] == '#' && farm[i][j] == '.') {
                                farm[i][j] = '#';
                                cnt++;
                            }
                        }
                        if (i < n - 1) {
                            if (farm[i + 1][j] == '#' && farm[i][j] == '.') {
                                farm[i][j] = '#';
                                cnt++;
                            }
                        }
                        if (j > 0) {
                            if (farm[i][j - 1] == '#' && farm[i][j] == '.') {
                                farm[i][j] = '#';
                                cnt++;
                            }
                        }
                        if (j < m - 1) {
                            if (farm[i][j + 1] == '#' && farm[i][j] == '.') {
                                farm[i][j] = '#';
                                cnt++;
                            }
                        }
                        if (i > 0 && j > 0) {
                            if (farm[i - 1][j - 1] == '#' && farm[i][j] == '.') {
                                farm[i][j] = '#';
                                cnt++;
                            }
                        }
                        if (i > 0 && j < m - 1) {
                            if (farm[i - 1][j + 1] == '#' && farm[i][j] == '.') {
                                farm[i][j] = '#';
                                cnt++;
                            }
                        }

                        if (i < n - 1 && j > 0) {
                            if (farm[i + 1][j - 1] == '#' && farm[i][j] == '.') {
                                farm[i][j] = '#';
                                cnt++;
                            }
                        }
                        if (i < n - 1 && j < m - 1) {
                            if (farm[i + 1][j + 1] == '#' && farm[i][j] == '.') {
                                farm[i][j] = '#';
                                cnt++;
                            }
                        }
                    }
                }

                for (int i = n - 1; i >= 0; i--) {
                    for (int j = 0; j < m; j++) {
                        if (i > 0) {
                            if (farm[i - 1][j] == '#' && farm[i][j] == '.') {
                                farm[i][j] = '#';
                                cnt++;
                            }
                        }
                        if (i < n - 1) {
                            if (farm[i + 1][j] == '#' && farm[i][j] == '.') {
                                farm[i][j] = '#';
                                cnt++;
                            }
                        }
                        if (j > 0) {
                            if (farm[i][j - 1] == '#' && farm[i][j] == '.') {
                                farm[i][j] = '#';
                                cnt++;
                            }
                        }
                        if (j < m - 1) {
                            if (farm[i][j + 1] == '#' && farm[i][j] == '.') {
                                farm[i][j] = '#';
                                cnt++;
                            }
                        }
                        if (i > 0 && j > 0) {
                            if (farm[i - 1][j - 1] == '#' && farm[i][j] == '.') {
                                farm[i][j] = '#';
                                cnt++;
                            }
                        }
                        if (i > 0 && j < m - 1) {
                            if (farm[i - 1][j + 1] == '#' && farm[i][j] == '.') {
                                farm[i][j] = '#';
                                cnt++;
                            }
                        }

                        if (i < n - 1 && j > 0) {
                            if (farm[i + 1][j - 1] == '#' && farm[i][j] == '.') {
                                farm[i][j] = '#';
                                cnt++;
                            }
                        }
                        if (i < n - 1 && j < m - 1) {
                            if (farm[i + 1][j + 1] == '#' && farm[i][j] == '.') {
                                farm[i][j] = '#';
                                cnt++;
                            }
                        }
                    }
                }

                for (int i = n - 1; i >= 0; i--) {
                    for (int j = m - 1; j >= 0; j--) {
                        if (i > 0) {
                            if (farm[i - 1][j] == '#' && farm[i][j] == '.') {
                                farm[i][j] = '#';
                                cnt++;
                            }
                        }
                        if (i < n - 1) {
                            if (farm[i + 1][j] == '#' && farm[i][j] == '.') {
                                farm[i][j] = '#';
                                cnt++;
                            }
                        }
                        if (j > 0) {
                            if (farm[i][j - 1] == '#' && farm[i][j] == '.') {
                                farm[i][j] = '#';
                                cnt++;
                            }
                        }
                        if (j < m - 1) {
                            if (farm[i][j + 1] == '#' && farm[i][j] == '.') {
                                farm[i][j] = '#';
                                cnt++;
                            }
                        }
                        if (i > 0 && j > 0) {
                            if (farm[i - 1][j - 1] == '#' && farm[i][j] == '.') {
                                farm[i][j] = '#';
                                cnt++;
                            }
                        }
                        if (i > 0 && j < m - 1) {
                            if (farm[i - 1][j + 1] == '#' && farm[i][j] == '.') {
                                farm[i][j] = '#';
                                cnt++;
                            }
                        }

                        if (i < n - 1 && j > 0) {
                            if (farm[i + 1][j - 1] == '#' && farm[i][j] == '.') {
                                farm[i][j] = '#';
                                cnt++;
                            }
                        }
                        if (i < n - 1 && j < m - 1) {
                            if (farm[i + 1][j + 1] == '#' && farm[i][j] == '.') {
                                farm[i][j] = '#';
                                cnt++;
                            }
                        }
                    }
                }
            }

            if (cnt > max) {
                max = cnt;
                cnt = 0;
            }

            if (max > n * m / 2) {
                break;
            }

            e = false;

            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if (farm[i][j] == '.') {
                        farm[i][j] = '#';
                        e = true;
                        break;
                    }
                }

                if (e) {
                    break;
                }
            }

            if (!e) {
                break;
            }

            cnt = 1;
        }
    }
    
    printf("%d", max);

    return 0;
}
