#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int power(int x, int a) {
    int y = 1;

    for (int i = 0; i < a; i++) {
        y *= x;
    }

    return y;
}

int binary_to_decimal(string binary) {
    int decimal = 0;

    reverse(binary.begin(), binary.end());

    for (int i = 0; i < binary.length(); i++) {
        if (binary[i] == '1') {
            decimal += power(2, i);
        }
    }

    return decimal;
}

int ternary_to_decimal(string ternary) {
    int decimal = 0;

    reverse(ternary.begin(), ternary.end());

    for (int i = 0; i < ternary.length(); i++) {
        if (ternary[i] == '1') {
            decimal += power(3, i);
        }
        else if (ternary[i] == '2') {
            decimal += 2 * power(3, i);
        }
    }

    return decimal;
}

int main() {
    string binary, ternary;

    cin >> binary >> ternary;

    for (int i = 0; i < binary.length(); i++) {
        string tmp = binary;

        if (tmp[i] == '0') {
            tmp[i] = '1';
        } else {
            tmp[i] = '0';
        }

        int binary_decimal = binary_to_decimal(tmp);

        for (int j = 0; j < ternary.length(); j++) {
            string tmp1 = ternary;

            if (tmp1[j] == '0') {
                tmp1[j] = '1';
                if (ternary_to_decimal(tmp1) == binary_decimal) {
                    cout << binary_decimal << endl;
                    return 0;
                }

                tmp1[j] = '2';
                if (ternary_to_decimal(tmp1) == binary_decimal) {
                    cout << binary_decimal << endl;
                    return 0;
                }
            } else if (tmp1[j] == '1') {
                tmp1[j] = '0';
                if (ternary_to_decimal(tmp1) == binary_decimal) {
                    cout << binary_decimal << endl;
                    return 0;
                }

                tmp1[j] = '2';
                if (ternary_to_decimal(tmp1) == binary_decimal) {
                    cout << binary_decimal << endl;
                    return 0;
                }
            } else {
                tmp1[j] = '0';
                if (ternary_to_decimal(tmp1) == binary_decimal) {
                    cout << binary_decimal << endl;
                    return 0;
                }

                tmp1[j] = '1';
                if (ternary_to_decimal(tmp1) == binary_decimal) {
                    cout << binary_decimal << endl;
                    return 0;
                }
            }
        }
    }

    return 0;
}
