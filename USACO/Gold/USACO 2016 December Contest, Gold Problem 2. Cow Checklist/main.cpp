#include <iostream>
#include <math.h>

#define INF 1000000000

using namespace std;

int H, G;
int h[1005][2], g[1005][2];
int mem[1005][1005][2];
bool e[1005][1005][2];

int dist(bool a, int x, bool b, int y) {
    return (int)pow(abs((a ? h[x][0] : g[x][0]) - (b ? h[y][0] : g[y][0])), 2) + (int)pow(abs((a ? h[x][1] : g[x][1]) - (b ? h[y][1] : g[y][1])), 2);;
}

int dp(int x, int y, bool c) {
    //if (e[x][y][c]) return mem[x][y][c];
    if (mem[x][y][c] != INF) return mem[x][y][c];

    //e[x][y][c] = true;

    if (c) {
        if (x < 1 || y < 0) return INF;
        return mem[x][y][c] = min(dp(x - 1, y, c) + dist(c, x, c, x - 1), dp(x - 1, y, !c) + dist(c, x, !c, y));
    }
    else {
        if (x <= 0 || y <= 0) return INF;
        return mem[x][y][c] = min(dp(x, y - 1, c) + dist(c, y, c, y - 1), dp(x, y - 1, !c) + dist(c, y, !c, x));
    }
}

int main() {
    freopen("checklist.in", "r", stdin);
    freopen("checklist.out", "w", stdout);

    cin >> H >> G;

    for (int i = 1; i <= H; i++) {
        cin >> h[i][0] >> h[i][1];
    }
    for (int i = 1; i <= G; i++) {
        cin >> g[i][0] >> g[i][1];
    }

    for (int i = 0; i <= H; i++) {
        for (int j = 0; j <= G; j++) {
            mem[i][j][0] = mem[i][j][1] = INF;
            e[i][j][0] = e[i][j][1] = false;
        }
    }

    mem[1][0][1] = 0;
    //e[1][0][1] = true;
    /*
    for (int j = 0; j <= G; j++) {
        e[0][j][0] = e[j][1][1] = true;
    }
     */

    cout << dp(H, G, 1) << endl;

    for (int i = 1; i <= H; i++) {
        for (int j = 1; j <= G; j++) {
            //cout << mem[i][j][0] << " " << mem[i][j][1] << "\t";
        }
        //cout << endl;
    }
}

/*
 * mem[x][y][H] = min(mem[x - 1][y][H] + dist(H[x], H[x - 1]), mem[x][y - 1][G] + dist(H[x], G[y - 1]))
 * mem[x][y][G] = min(mem[x - 1][y][H] + dist(G[y], H[x - 1]), mem[x][y - 1][G] + dist(G[y], G[y - 1]))
 */
/*
2 7
0 0
0 8
2 1
2 2
2 3
2 4
2 5
2 6
2 7
 */