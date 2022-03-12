#include <iostream>
#include <algorithm>

using namespace std;

int N, B;
int f[100000], s[100000], d[100000];
int n[100000], p[100000];
int f_idx[100000], b_idx[100000];
int ans[100000];

bool sortF(int a, int b) {
    return f[a] > f[b];
}

bool sortB(int a, int b) {
    return s[a] > s[b];
}

int main() {
    freopen("snowboots.in", "r", stdin);
    freopen("snowboots.out", "w", stdout);

    cin >> N >> B;

    for (int i = 0; i < N; i++) {
        cin >> f[i];
        f_idx[i] = i;

        n[i] = i + 1;
        p[i] = i - 1;
    }

    for (int i = 0; i < B; i++) {
        cin >> s[i] >> d[i];
        b_idx[i] = i;
    }

    sort(f_idx, f_idx + N, sortF);
    sort(b_idx, b_idx + B, sortB);


    int max_step = 1;
    int j = 0;
    for (int i = 0; i < B; i++) {
        while (j < N && s[b_idx[i]] < f[f_idx[j]]) {
            p[n[f_idx[j]]] = p[f_idx[j]];
            n[p[f_idx[j]]] = n[f_idx[j]];
            max_step = max(max_step, n[f_idx[j]] - p[f_idx[j]]);
            j++;
        }

        //cout << s[b_idx[i]] << " " << max_step << endl;

        ans[b_idx[i]] = max_step <= d[b_idx[i]];
    }

    for (int i = 0; i < B; i++) {
        cout << ans[i] << endl;
    }

    return 0;
}

/*
 0 3 8 5 6 9 0 0
 number of tiles can't go over in a row >= d[i] => 0
 0 5
 0 6
 6 2
 8 1
 10 1
 5 3
 150 7

 0[0] 0[6] 0[7] 3[1] 5[3] 6[4] 8[2] 9[5]
 0 5
 0 6
 5 3
 6 2
 8 1
 10 1
 150 7

 0 5 => 0, 6, 7
 0 6 => 0, 6, 7
 5 3 => 0, 6, 7, 1, 3 => 0, 1, 3, 6, 7
 6 2 => 0, 1, 3, 6, 7, 4 => 0, 1, 3, 4, 6, 7
 8 1 => 0, 1, 3, 4, 6, 7, 2 => 0, 1, 2, 3, 4, 6, 7
 10 1 => 0, 1, 2, 3, 4, 6, 7, 5 => 0, 1, 2, 3, 4, 5, 6, 7
 150 7 =>  0, 1, 2, 3, 4, 5, 6, 7
 */
