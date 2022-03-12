#include <iostream>
#include <stack>

using namespace std;

int main() {
    int N;

    cin >> N;

    stack<int> s;

    for (int i = 0; i < N; i++) {
        int tmp;

        cin >> tmp;

        s.push(tmp);
    }

    int max, cnt;

    max = cnt = 0;

    for (int i = 0; i < N; i++) {
        int tmp = s.top();

        if (tmp > max) {
            cnt++;
            max = tmp;
        }

        s.pop();
    }

    cout << cnt;

    return 0;
}
