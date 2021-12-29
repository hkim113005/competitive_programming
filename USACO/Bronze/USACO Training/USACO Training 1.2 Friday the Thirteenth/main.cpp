/*
ID: Hyungjae Kim (hyungja1)
LANG: C++
TASK: friday
*/
#include <iostream>

bool leap(int year){
    if (year % 400 == 0) {
        return true;
    }
    else if (year % 4 == 0 && year % 100 != 0) {
        return true;
    }
    return false;
}

int main() {
    freopen("friday.in", "r", stdin);
    freopen("friday.out", "w", stdout);

    int N, day = 0, year = 1900,  days[7] = { 0 };
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 12; j++) {
            if (i == 0 && j == 0) {
                day = 12;
            } else if (j - 1 == 3 || j - 1 == 5 || j - 1 == 8 || j - 1 == 10) {
                day += 30;
            } else if (j - 1 == 1) {
                if (leap(year)) {
                    day += 29;
                } else {
                    day += 28;
                }
            } else {
                day += 31;
            }
            days[(2 + (day % 7)) % 7]++;
        }
        year++;
    }
    for (int i = 0; i < 7; i++) {
        if (i != 6) {
            printf("%d ", days[i]);
        } else {
            printf("%d\n", days[i]);
        }
    }
}
