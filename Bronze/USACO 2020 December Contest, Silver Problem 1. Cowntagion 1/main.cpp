#include <iostream>
#include <math.h>

using namespace std;

int n;

int main() {
    cin >> n;

    double m = sqrt(n);

    int x;

    if (m - int(m) != 0) {
        x = m + 1;
    }
    else {
        x = m;
    }



    return 0;
}
