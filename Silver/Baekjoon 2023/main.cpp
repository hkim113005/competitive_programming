#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

int n;
vector<int> ans;

bool prime(int x) {
    for (int i = 2; i <= x / 2; i++) {
        if (x % i == 0) {
            return false;
        }
    }

    return true;
}

int power(int x, int a) {
    int r = 1;

    for (int i = 0; i < a; i++) {
        r *= x;
    }

    return r;
}

void process (int a) {
    if (prime(a)) {
        if (a / power(10, n - 1) > 0) {
            ans.push_back(a);

            return;
        }
    }
    else {
        return;
    }

    for (int i = 1; i < 10; i += 2) {
        process(a * 10 + i);
    }
}

int main() {
    cin >> n;

    for (int i = 2; i < 10; i++) {
        process(i);
    }

    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << endl;
    }

    return 0;
}
