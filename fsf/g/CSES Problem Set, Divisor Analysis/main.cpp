#include <iostream>
#include <assert.h>

#define int int64_t
#define ll long long
#define MOD 1000000007

using namespace std;

struct mi { // WARNING: needs some adjustment to work with FFT
    int v; explicit operator int() const { return v; }
    mi():v(0) {}
    mi(ll _v):v(int(_v%MOD)) { v += (v<0)*MOD; }
};
mi& operator+=(mi& a, mi b) {
    if ((a.v += b.v) >= MOD) a.v -= MOD;
    return a; }
mi& operator-=(mi& a, mi b) {
    if ((a.v -= b.v) < 0) a.v += MOD;
    return a; }
mi operator+(mi a, mi b) { return a += b; }
mi operator-(mi a, mi b) { return a -= b; }
mi operator*(mi a, mi b) { return mi((ll)a.v*b.v); }
mi& operator*=(mi& a, mi b) { return a = a*b; }
mi pow(mi a, ll p) { assert(p >= 0); // won't work for negative p
    return p==0?1:pow(a*a,p/2)*(p&1?a:1); }
mi inv(mi a) { assert(a.v != 0); return pow(a,MOD-2); }
mi operator/(mi a, mi b) { return a*inv(b); }
bool operator==(mi a, mi b) { return a.v == b.v; }

int n;
int x[100005], k[100005];

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

int lcm(int a, int b) {
    return a * b / gcd(a, b);
}

int POW(int b, int e) {
    if (e == 0) return 1;
    mi res = POW(b, e / 2);
    res *= res;
    if (e % 2) res *= b;
    return (int)res;
}

int num() {
    mi res = 1;
    for (int i = 0; i < n; i++) {
        res *= (k[i] + 1);
    }
    return (int)res;
}

int sum() {
    mi res = 1;
    for (int i = 0; i < n; i++) {
        res *= (POW(x[i], (k[i] + 1) % (MOD - 1)) - 1) * POW(x[i] - 1, MOD - 2) % MOD;
    }
    return (int)res;
}

int pro() {
    int num = 1;
    bool divided = false;
    for (int i = 0; i < n; i++) {
        if (k[i] % 2 == 1 && !divided) {
            num *= (k[i] + 1) / 2 % (MOD - 1);
            num %= (MOD - 1);
            divided = true;
        }
        else {
            num *= (k[i] + 1) % (MOD - 1);
            num %= (MOD - 1);
        }
    }
    if (!divided) {
        for (int i = 0; i < n; i++) {
            k[i] /= 2;
        }
    }

    mi number = 1;
    for (int i = 0; i < n; i++) {
        number *= POW(x[i], k[i]);
    }
    return POW((int)number, num);
}

int32_t main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> k[i];
    }

    cout << num() << " ";
    cout << sum() << " ";
    cout << pro() << endl;

    return 0;
}
