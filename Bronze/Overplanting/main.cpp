#include <iostream>
#include <vector>
#include <tuple>

using namespace std;

int n;
vector<tuple<int, int, int, int>> grass;

int main() {
    cin >> n;

    grass.resize(n);

    for (int i = 0; i < n; i++) {
        cin >> get<0>(grass[i]) >> get<1>(grass[i]) >> get<2>(grass[i]) >> get<3>(grass[i]);
    }

    int m = 0, f = 0;

    vector<tuple<int, int, int, int>> dif;
    dif.resize(n);

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            tuple<int, int, int, int> minus;

            if (get<0>(grass[i]) > get<0>(grass[j])) {
                get<0>(minus) = get<0>(grass[i]);
            }
            else {
                get<0>(minus) = get<0>(grass[j]);
            }

            if (get<1>(grass[i]) < get<1>(grass[j])) {
                get<1>(minus) = get<1>(grass[i]);
            }
            else {
                get<1>(minus) = get<1>(grass[j]);
            }

            if (get<2>(grass[i]) < get<2>(grass[j])) {
                get<2>(minus) = get<2>(grass[i]);
            }
            else {
                get<2>(minus) = get<2>(grass[j]);
            }

            if (get<3>(grass[i]) > get<3>(grass[j])) {
                get<3>(minus) = get<3>(grass[i]);
            }
            else {
                get<3>(minus) = get<3>(grass[j]);
            }

            if (get<0>(minus) < get<2>(minus) && get<1>(minus) > get<3>(minus)) {
                dif.push_back(minus);
                m += (get<2>(minus) - get<0>(minus)) * (get<1>(minus) - get<3>(minus));
            }
        }
    }

    for (int i = 0; i < dif.size(); i++) {
        for (int j = i + 1; j < dif.size(); j++) {
            tuple<int, int, int, int> minus;

            if (get<0>(dif[i]) > get<0>(dif[j])) {
                get<0>(minus) = get<0>(dif[i]);
            }
            else {
                get<0>(minus) = get<0>(dif[j]);
            }

            if (get<1>(dif[i]) < get<1>(dif[j])) {
                get<1>(minus) = get<1>(dif[i]);
            }
            else {
                get<1>(minus) = get<1>(dif[j]);
            }

            if (get<2>(dif[i]) < get<2>(dif[j])) {
                get<2>(minus) = get<2>(dif[i]);
            }
            else {
                get<2>(minus) = get<2>(dif[j]);
            }

            if (get<3>(dif[i]) > get<3>(dif[j])) {
                get<3>(minus) = get<3>(dif[i]);
            }
            else {
                get<3>(minus) = get<3>(dif[j]);
            }

            if (get<0>(minus) < get<2>(minus) && get<1>(minus) > get<3>(minus)) {
                m -= (get<2>(minus) - get<0>(minus)) * (get<1>(minus) - get<3>(minus));
            }
        }
    }

    int t = 0;

    for (int i = 0; i < n; i++) {
        t += (get<2>(grass[i]) - get<0>(grass[i])) * (get<1>(grass[i]) - get<3>(grass[i]));
    }

    cout << t - m;

    return 0;
}
