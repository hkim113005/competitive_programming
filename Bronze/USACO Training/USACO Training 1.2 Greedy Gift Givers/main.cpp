/*
ID: Hyungjae Kim (hyungja1)
LANG: C++
TASK: gift1
*/
#include <iostream>
#include <string.h>

using namespace std;

struct person {
    char name[15];
    int money = 0;
};

person p[11];

int find(char nme[15]) {
    for (int i = 0; i < 11; i++) {
        if (strcmp(nme, p[i].name) == 0) {
            return i;
        }
    }
}

int main() {
    freopen("gift1.in", "r", stdin);
    freopen("gift1.out", "w", stdout);

    int NP = 0, n = 0, mny = 0, gft = 0;
    char nme[15];
    for (char & i : nme) {
        i = ' ';
    }
    scanf("%d", &NP);
    for (int i = 0; i < NP; i++) {
        for (char & j : p[i].name) {
            j = ' ';
        }
        scanf("%s", p[i].name);
    }
    for (int i = 0; i < NP; i++) {
        scanf("%s %d %d", nme, &mny, &n);
        if (n != 0) {
            p[find(nme)].money += ((mny % n) - mny);
            mny -= mny % n;
            for (int j = 0; j < n; j++) {
                scanf("%s", nme);
                p[find(nme)].money += mny / n;
            }
        }
    }
    for (int i = 0; i < NP; i++) {
            printf("%s %d\n", p[i].name, p[i].money);
    }
}
