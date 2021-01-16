#include <iostream>
#include <stdio.h>
#include <fstream>
#include <string.h>
#include <algorithm>

using namespace std;

int cnt = 0;
bool board[3] = {true, true, true};

struct cow {
    int order;
    char name[10];
    int milk;
    bool operator<(const cow&r)const {
        return order < r.order;
    }
} plusminus[100], Bessie, Elsie, Mildred;

void milk(int i) {
    if (strcmp(plusminus[i].name, Bessie.name) == 0) {
        Bessie.milk += plusminus[i].milk;
    }
    else if (strcmp(plusminus[i].name, Elsie.name) == 0) {
        Elsie.milk += plusminus[i].milk;
    }
    else if (strcmp(plusminus[i].name, Mildred.name) == 0) {
        Mildred.milk += plusminus[i].milk;
    }
}

void change() {
    bool newboard[3] = { false }, different = false;
    if (Bessie.milk >= Elsie.milk && Bessie.milk >= Mildred.milk) {
        newboard[0] = true;
    }
    if (Elsie.milk >= Bessie.milk && Elsie.milk >= Mildred.milk) {
        newboard[1] = true;
    }
    if (Mildred.milk >= Bessie.milk && Mildred.milk >= Elsie.milk) {
        newboard[2] = true;
    }
    for (int i = 0; i < 3; i++) {
        if (board[i] != newboard[i]) {
            different = true;
        }
    }
    if (different) {
        for (int i = 0; i < 3; i++) {
            board[i] = newboard[i];
        }
        cnt++;
    }
}

int main() {
    freopen("measurement.in", "r", stdin);
    freopen("measurement.out", "w", stdout);

    int N;
    char sign;
    strcpy(Bessie.name, "Bessie");
    Bessie.milk = 7;
    strcpy(Elsie.name, "Elsie");
    Elsie.milk = 7;
    strcpy(Mildred.name, "Mildred");
    Mildred.milk = 7;

    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d %s %c %d", &plusminus[i].order, plusminus[i].name, &sign, &plusminus[i].milk);
        if (sign == '-') {
            plusminus[i].milk *= -1;
        }
        //printf("%d %s %c %d", plusminus[i].order, plusminus[i].name, sign, plusminus[i].milk);
    }
    sort(plusminus, plusminus + N);
    for (int i = 0; i < N; i++) {
        milk(i);
        change();
    }
    printf("%d", cnt);
}