#include <iostream>

bool gene(char spots[100], char plains[100], int n) {
    bool spot_a = false, spot_c = false, spot_g = false, spot_t = false;
    bool plain_a = false, plain_c = false, plain_g = false, plain_t = false;

    for (int i = 0; i < n; i++) {
        if (spots[i] == 'A') {
            spot_a = true;
        }
        else if (spots[i] == 'C') {
            spot_c = true;
        }
        else if (spots[i] == 'G') {
            spot_g = true;
        }
        else if (spots[i] == 'T') {
            spot_t = true;
        }

        if (plains[i] == 'A') {
            plain_a = true;
        }
        else if (plains[i] == 'C') {
            plain_c = true;
        }
        else if (plains[i] == 'G') {
            plain_g = true;
        }
        else if (plains[i] == 'T') {
            plain_t = true;
        }
    }

    if (spot_a && plain_a) {
        return false;
    }
    if (spot_c && plain_c) {
        return false;
    }
    if (spot_g && plain_g) {
        return false;
    }
    if (spot_t && plain_t) {
        return false;
    }
    return true;
}

int main() {
    int n, m, cnt = 0;
    char spot[100][1000], plain[100][1000];
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%s", spot[i]);
    }
    for (int i = 0; i < n; i++) {
        scanf("%s", plain[i]);
    }

    for (int i = 0; i < m; i++) {
        char spots[100], plains[100];
        for (int j = 0; j < n; j++) {
            spots[j] = spot[j][i];
            plains[j] = plain[j][i];
        }
        if (gene(spots, plains, n)) {
            cnt++;
        }
    }

    printf("%d", cnt);
}
