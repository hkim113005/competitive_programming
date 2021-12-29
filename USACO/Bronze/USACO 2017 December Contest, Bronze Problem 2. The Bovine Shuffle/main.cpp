#include <iostream>
#include <stdio.h>
#include <fstream>

using namespace std;

int main() {
    freopen("shuffle.in", "r", stdin);
    freopen("shuffle.out", "w", stdout);

    int n, switch1[101], switch2[101], tmp1[101];
    string names[101];
    string tmp[101];
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &switch1[i]);
        switch1[i] -= 1;
        switch2[i] = i;
        //cout << swtch[i] << "\n";
    }
    for (int i = 0; i < n; i++) {
        cin >> names[i];
        //cout << nmes[i] << "\n";
    }
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < n; j++) {
            tmp1[switch1[j]] = switch2[j];
        }
        for (int j = 0; j < n; j++) {
            switch2[j] = tmp1[j];
            //cout << nmes[i] << i;
        }
    }
    for (int j = 0; j < n; j++) {
        tmp[switch2[j]] = names[j];
    }
    for (int i = 0; i < n; i++) {
        cout << tmp[i] << "\n";
    }
}
