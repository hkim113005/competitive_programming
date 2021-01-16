/*
ID: Hyungjae Kim (hyungja1)
LANG: C++
TASK: ride
*/
#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

int main() {
    freopen("ride.in", "r", stdin);
    freopen("ride.out", "w", stdout);

    char ufo[100], group[100];
    int u = 1, g = 1;
    scanf("%s %s", ufo, group);
    for (int i = 0; i < strlen(ufo); i++) {
        u *= ufo[i] - 64;
    }
    for (int i = 0; i < strlen(group); i++) {
        g *= group[i] - 64;
    }
    if (u % 47 == g % 47) {
        printf("GO\n");
    }
    else {
        printf("STAY\n");
    }
}
