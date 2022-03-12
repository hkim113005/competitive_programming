#include <iostream>
#include <stdio.h>
#include <fstream>

using namespace std;

typedef struct node {
    int from = -1;
    int to = -1;
    int cost = 0;
} node;

node cities[1000][100000];

int m = 100000, cnt = 0, length[100000];

void v(int a, int b, int cost, int loop, int c) {
    //printf("%d", loop);
    if (loop > 100000) {
        return;
    }
    if (c >= cnt) {
        return;
    }
    for (int i = 0; i < length[c]; i++) {
        if (cities[c][i].from == a && cities[c][i].to == b) {
            if (cities[c][i].cost < m) {
                m = cities[c][i].cost;
            }
        }
        if (cities[c][i].from == b && loop > 0) {
            if (cost + cities[c][i].cost < m) {
                m = cost + cities[c][i].cost;
            }
            return;
        }
        else if (cities[c][i].from == a) {
            if (c > 0) {
                v(cities[c][i].to, b, cost + cities[c][i].cost, loop + 1, c + 1);
                v(cities[c][i].to, b, cost + cities[c][i].cost, loop + 1, c - 1);
            }
            else {
                v(cities[c][i].to, b, cost + cities[c][i].cost, loop + 1, c + 1);
            }
        }
    }
    v(a, b, cost, loop, c + 1);
}

int main() {
    freopen("cowroute.in", "r", stdin);
    freopen("cowroute.out", "w", stdout);

    int a, b, n, tmp[100000], c, d;
    scanf("%d %d %d", &a, &b, &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &c, &d);
        for (int j = 0; j < d; j++) {
            scanf("%d", &tmp[j]);
            if (j != d - 1) {
                cities[cnt][j].cost = c;
            }
        }
        for (int j = 0; j < d; j++) {
            for (int k = j + 1; k < d; k++) {
                cities[cnt][j].from = tmp[j];
                cities[cnt][j].to = tmp[k];
            }
        }
        length[cnt] = d;
        cnt++;
    }
    v(a, b, 0, 0, 0);
    if (m == 100000) {
        m = -1;
    }
    printf("%d\n", m);
}
