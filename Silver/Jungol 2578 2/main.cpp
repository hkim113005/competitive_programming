#include <iostream>

using namespace std;

int n, m, k;
int bus[5005][4];
int s_x, s_y;
int t_x, t_y;
int possible_points[5005][1000];

void input() {
    cin >> m >> n;

    cin >> k;

    for (int i = 0; i < k; i++) {
        cin >> bus[i][0] >> bus[i][1] >> bus[i][2] >> bus[i][3];

        bus[i][0]--;
        bus[i][1]--;
        bus[i][2]--;
        bus[i][3]--;
    }

    cin >> s_x >> s_y;
    cin >> t_x >> t_y;

    s_x--;
    s_y--;
    t_x--;
    t_y--;
}

void find_possible_points() {

}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
