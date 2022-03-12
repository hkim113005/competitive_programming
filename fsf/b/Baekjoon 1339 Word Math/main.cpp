#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <math.h>

using namespace std;

int n;
vector<pair<int, char>> a(26);

int main() {
    for (int i = 0; i < 26; i++) {
        a[i].second = 'A' + i;
    }

    cin >> n;

    for (int i = 0; i < n; i++) {
        string tmp;

        cin >> tmp;

        for (int j = tmp.length() - 1; j >= 0; j--) {
            a[tmp[tmp.length() - j - 1] - 'A'].first += pow(10, j);
        }
    }

    sort(a.begin(), a.end());

    int ans = 0;

    for (int i = 0; i < 10; i++) {
        ans += a[25 - i].first * (9 - i);
    }

    cout << ans;

    return 0;
}
