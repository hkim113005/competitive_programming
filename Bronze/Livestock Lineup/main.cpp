#include <iostream>
#include <string.h>
#include <fstream>

using namespace std;

typedef struct cow {
    int len = 0;
    int c[10]{};
} cow;

cow cows[10];

int index_of(string s) {
    if (s == "Beatrice") {
        return 0;
    }
    else if (s == "Belinda") {
        return 1;
    }
    else if (s == "Bella") {
        return 2;
    }
    else if (s == "Bessie") {
        return 3;
    }
    else if (s == "Betsy") {
        return 4;
    }
    else if (s == "Blue") {
        return 5;
    }
    else if (s == "Buttercup") {
        return 6;
    }
    else if (s == "Sue") {
        return 7;
    }
}

string name_of(int i) {
    if (i == 0) {
        return "Beatrice";
    }
    else if (i == 1) {
        return "Belinda";
    }
    else if (i == 2) {
        return "Bella";
    }
    else if (i == 3) {
        return "Bessie";
    }
    else if (i == 4) {
        return "Betsy";
    }
    else if (i == 5) {
        return "Blue";
    }
    else if (i == 6) {
        return "Buttercup";
    }
    else if (i == 7) {
        return "Sue";
    }
}

int main() {
    //freopen("lineup.in", "r", stdin);
    //freopen("lineup.out", "w", stdout);

    int n;

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        int a, b;
        string tmp;

        cin>>tmp;

        a = index_of(tmp);

        cin>>tmp>>tmp>>tmp>>tmp>>tmp;

        b = index_of(tmp);

        cows[a].c[cows[a].len] = b;
        cows[a].len++;

        cows[b].c[cows[b].len] = a;
        cows[b].len++;
    }

    string final = "";

    for (int i = 0; i < 8; i++) {
        if (cows[i].len == 1) {
            string tmp = "";

            tmp += name_of(i);
            tmp += "\n";

            int x = cows[cows[i].c[0]].len;

            if (x == 1) {
                tmp += name_of(cows[i].c[0]);
                tmp += "\n";

                cows[i].len = -1;
                cows[cows[i].c[0]].len = -1;
            }
            else if (x == 2){
                int z = cows[i].c[0];

                cows[i].len = -1;

                while (true) {
                    int y = 0;

                    if (cows[z].c[0] == i) {
                        y = 1;
                    }
                    else if (cows[z].c[1] == i) {
                        y = 0;
                    }

                    tmp += name_of(z);
                    tmp += "\n";

                    if (cows[z].len == 1) {
                        cows[z].len = -1;
                        break;
                    }
                    else {
                        cows[z].len = -1;
                        z = cows[z].c[y];
                    }
                }
            }

            final += tmp;
        }
        else if (cows[i].len == 0) {
            final += name_of(i);
            final += "\n";
        }
    }

    cout<<final;

    return 0;
}
