#include <iostream>
#include <vector>
#include <map>

using namespace std;

int n, k;
int a[100005];

vector<pair<int, int>> factor(int x) {
    map<int, int> factors;
    for (int i = 2; i * i <= x; i++) {
        while (x % i == 0) {
            x /= i;
            factors[i]++;
        }
    }
    if (x > 1) {
        factors[x]++;
    }

    vector<pair<int, int>> prime_factors;
    for (pair<int, int> prime : factors) {
        if (prime.second % k > 0) {
            prime_factors.emplace_back(make_pair(prime.first, prime.second % k));
        }
    }

    return prime_factors;
}

vector<pair<int, int>> inverse(vector<pair<int, int>> o) {
    vector<pair<int, int>> p(o.size());
    for (int i = 0; i < o.size(); i++) {
        p[i].first = o[i].first;
        p[i].second = k - o[i].second;
    }

    return p;
}

int main() {
    cin >> n >> k;
    map<vector<pair<int, int>>, int> factors;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        factors[factor(a[i])]++;
    }

    long long ans = 0;
    for (int i = 0; i < n; i++) {
        if (factor(a[i]) == inverse(factor(a[i]))) {
            ans += (factors[factor(a[i])] - 1);
        }
        else {
            ans += factors[inverse(factor(a[i]))];
        }
    }
    cout << ans / 2;

    return 0;
}