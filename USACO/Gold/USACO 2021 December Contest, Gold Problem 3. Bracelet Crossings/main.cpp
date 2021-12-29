#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int T, N, M;
bool a[200][200];
bool b[200][200];
bool d[200][200];
int pre[200];

bool solve() {
    int k[105], c[105][105];
    for (int j = 0; j < M; j++) {
        cin >> k[j];
        for (int l = 0; l < k[j]; l++) {
            cin >> c[j][l];
        }


    }
    for (int j = 0; j < M; j++) {
        bool open[100];
        for (int l = 1; l <= N; l++) {
            open[l] = false;
        }
        stack<int> last;
        vector<int> closed;
        vector<int> opened;
        for (int l = 0; l < k[j]; l++) {
            if (!open[c[j][l]]) {
                last.push(c[j][l]);
                open[c[j][l]] = true;
                for (int i = 0; i < opened.size(); i++) {
                    if (d[c[j][l]][opened[i]]) return false;
                    d[opened[i]][c[j][l]] = true;
                }
                opened.emplace_back(c[j][l]);
            }
            else {
                if (last.top() != c[j][l]) return false;
                else {
                    last.pop();
                    stack<int> copy = last;
                    while (!copy.empty()) {
                        if (a[c[j][l]][copy.top()]) return false;
                        a[copy.top()][c[j][l]] = true;
                        copy.pop();
                    }
                    for (int i = 0; i < closed.size(); i++) {
                        if (b[c[j][l]][closed[i]]) return false;
                        b[closed[i]][c[j][l]] = true;
                    }
                    closed.emplace_back(c[j][l]);
                    if (pre[c[j][l]] != j - 1 && pre[c[j][l]] != -1) return false;
                    pre[c[j][l]] = j;
                }
            }
        }
    }

    return true;
}

int main() {
    cin >> T;
    for (int i = 0; i < T; i++) {
        cin >> N >> M;
        for (int j = 0; j <= N; j++) {
            for (int k = 0; k <= N; k++) {
                a[j][k] = false;
                b[j][k] = false;
                d[j][k] = false;
            }
            pre[j] = -1;
        }
        cout << (solve() ? "YES" : "NO") << endl;
    }
    return 0;
}
