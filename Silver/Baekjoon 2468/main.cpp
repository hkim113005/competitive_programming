#include <iostream>

using namespace std;

int N;
int land[100][100];
int min = -1;
int max = -1;

int main() {
    cin >> N;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> land[i][j];
        }
    }


    return 0;
}
