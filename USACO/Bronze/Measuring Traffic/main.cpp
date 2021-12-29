#include <iostream>

using namespace std;

int main() {
    int n, m = 0, traffic[1000][3], traffic_filtered[1000][3];

    cin >> n;

    for (int i = 0; i < n; i++) {
        string tmp;

        cin >> tmp >> traffic[i][1] >> traffic[i][2];

        if (tmp == "none") {
            traffic[i][0] = 0;
        }
        else if (tmp == "on") {
            traffic[i][0] = 1;
        }
        else if (tmp == "off") {
            traffic[i][0] = 2;
        }
    }

    for (int i = 0; i < n; i++) {
        if (traffic[i][0] == 0 && traffic[i + 1][0] == 0) {
            int min = -1, max = -1;
            int cnt = 0;

            for (int j = i; j < n; j++) {
                if (traffic[j][0] == 0) {
                    if (min > traffic[j][2] || min == -1) {
                        min = traffic[j][2];
                    }

                    if (max < traffic[j][1] || max == -1) {
                        max = traffic[j][1];
                    }
                    cnt++;
                }
                else {
                    i += cnt - 1;
                    break;
                }
            }

            traffic_filtered[m][0] = 0;
            traffic_filtered[m][1] = max;
            traffic_filtered[m][2] = min;

            m++;
        }
        else {
            traffic_filtered[m][0] = traffic[i][0];
            traffic_filtered[m][1] = traffic[i][1];
            traffic_filtered[m][2] = traffic[i][2];

            m++;
        }
    }

    for (int i = 0; i < m; i++) {
        cout << traffic_filtered[i][0] << " " << traffic_filtered[i][1] << " " << traffic_filtered[i][2] << endl;
    }

    return 0;
}
