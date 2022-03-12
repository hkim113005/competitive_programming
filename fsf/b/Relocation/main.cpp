#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Node {
public:
    pair<int, int> t;
};

int n, m, k;
vector<int> markets;
vector<pair<int, Node>> roads;
vector<int> travelled;

int main() {
    bool ok = false;

    cin >> n >> m >> k;

    markets.resize(k);

    for (int i = 0; i < k; i++) {
        cin >> markets[k];
    }

    roads.resize(m);

    for (int i = 0; i < m; i++) {
        cin >> roads[i].second.t.first >> roads[i].second.t.second >> roads[i].first;
    }

    sort(roads.begin(), roads.end());

    for (int i = 0; i < m; i++) {
        int a = roads[i].second.t.first;
        int b = roads[i].second.t.second;

        if (!ok) {
            if (count(markets.begin(), markets.end(), a) && count(markets.begin(), markets.end(), b)) {


            }
            else if (count(markets.begin(), markets.end(), a) || count(markets.begin(), markets.end(), b)) {
            }
        }
        else {

        }
    }

    return 0;
}
