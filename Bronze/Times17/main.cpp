#include <iostream>
#include <string>
#include <algorithm>
#include <fstream>

using namespace std;

string binary_addition(string a, string b) {
    int carry = 0;
    string sum;

    for (int i = 0; i < b.length(); i++) {
        if (i < a.length()) {
            if (a[i] == '1' && b[i] == '1') {
                if (carry == 0) {
                    sum += '0';
                    carry = 1;
                } else {
                    sum += '1';
                    carry = 1;
                }
                carry = 1;
            } else if (a[i] == '0' && b[i] == '0') {
                if (carry == 1) {
                    sum += '1';
                }
                else {
                    sum += '0';
                }
                carry = 0;
            } else {
                if (carry == 1) {
                    sum += '0';
                    carry = 1;
                } else {
                    sum += '1';
                    carry = 0;
                }
            }
        }
        else {
            if (b[i] == '1' && carry == 1) {
                sum += '0';
                carry = 1;
            }
            else if (b[i] == '0' && carry == 0) {
                sum += '0';
                carry = 0;
            }
            else {
                sum += '1';
                carry = 0;
            }
        }
    }

    if (carry == 1) {
        sum += '1';
    }

    return sum;
}

int main() {
    //freopen("times17.in", "r", stdin);
    //freopen("times17.out", "w", stdout);

    string input, a, b;

    cin >> input;

    a = input;
    b = input + "0000";

    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());

    string sum = binary_addition(a, b);
    reverse(sum.begin(), sum.end());

    cout << sum << endl;

    return 0;
}
