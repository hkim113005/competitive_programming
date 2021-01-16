#include <iostream>
#include <vector>
#include <algorithm>

#define MAX 1000000

using namespace std;

int n;
vector<int> weights;

int main() {
    cin >> n;

    weights.resize(n);

    for (int i = 0; i < n; i++) {
        cin >> weights[i];
    }

    sort(weights.begin(), weights.end());

    int sum = 0;
    for (int i = 0; i < n; i++) {
        if (sum + 1 >= weights[i]) {
            sum += weights[i];
        }
        else {
            break;
        }
    }

    cout << sum + 1;

    return 0;
}
