#include <iostream>
#include <vector>

using namespace std;

int main() {
    int M, N, K;
    int board[105][105];
    int cnt = 2;
    vector<int> areas;

    cin >> M >> N >> K;

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            board[i][j] = 0;
        }
    }

    for (int i = 0; i < K; i++) {
        int tx1, tx2;
        int ty1, ty2;

        cin >> tx1 >> ty1 >> tx2 >> ty2;

        for (int j = ty1; j < ty2; j++) {
            for (int k = tx1; k < tx2; k++) {
                board[j][k] = 1;
            }
        }
    }

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < M; k++) {
                for (int l = 0; l < N; l++) {
                    cout << board[k][l] << " ";
                }

                cout << endl;
            }

            cout << endl << endl;

            bool e = true;

            if (board[i][j] == 0) {
                if (i - 1 >= 0) {
                    if (board[i - 1][j] > 1) {
                        areas[board[i - 1][j] - 3]++;
                        board[i][j] = board[i - 1][j];

                        e = false;
                    }
                }

                if (i + 1 < M) {
                    if (board[i + 1][j] > 1) {
                        areas[board[i + 1][j] - 3]++;
                        board[i][j] = board[i + 1][j];

                        e = false;
                    }
                }

                if (j - 1 >= 0) {
                    if (board[i][j - 1] > 1) {
                        areas[board[i][j - 1] - 3]++;
                        board[i][j] = board[i][j - 1];

                        e = false;
                    }
                }

                if (j + 1 < N) {
                    if (board[i][j + 1] > 1) {
                        areas[board[i][j + 1] - 3]++;
                        board[i][j] = board[i][j + 1];

                        e = false;
                    }
                }

                if (e) {
                    areas.push_back(1);
                    cnt++;
                    board[i][j] = cnt;
                }
            }
        }
    }

    cout << areas.size() << endl;

    for (int i = 0; i < areas.size(); i++) {
        cout << areas[i] << endl;
    }

    return 0;
}
