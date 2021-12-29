#include <iostream>
#include <vector>

using namespace std;

int n;
vector<vector<int>> possible;

void process(vector<int> a) {
    if (a.size() == n) {
        possible.push_back(a);

        return;
    }

    for (int i = a[a.size() - 1]; i < 7; i++) {
        vector<int> b = a;
        b.push_back(i);
        process(b);
    }
}

int main() {
    cin >> n;

    for (int i = 1; i < 7; i++) {
        vector<int> a;
        a.push_back(i);
        process(a);
    }

    for (int i = 0; i < possible.size(); i++) {
        for (int j = 0; j < n; j++) {
            cout << possible[i][j] << " ";
        }

        cout << endl;
    }

    return 0;
}
