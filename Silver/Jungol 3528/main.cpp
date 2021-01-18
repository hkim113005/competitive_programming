#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int n, cnt = 0, c = 0;
string word;
vector<string> done;

bool in(string a) {
    for (int i = 0; i < done.size(); i++) {
        if (a == done[i]) {
            return true;
        }
    }

    return false;
}

void process(string a, vector<pair<char, int>> possible) {
    cout << c << endl;
    c++;
    //cout << a;

    if (c > 720) {
        cout << c << endl;
    }

    if (a.length() == n) {
        if (!in(a)) {
            done.push_back(a);
            cnt++;
        }
        return;
    }

    for (int i = 0; i < possible.size(); i++) {
        if (a[a.length() - 1] != possible[i].first && possible[i].second > 0) {
            string b = a;
            b += possible[i].first;

            vector<pair<char, int>> p = possible;
            p[i].second--;

            process(b, p);
        }
    }
}

int find(vector<pair<char, int>> p, char x) {
    for (int i = 0; i < p.size(); i++) {
        if (p[i].first == x) {
            return i;
        }
    }

    return -1;
}

int main() {
    cin >> word;

    n = word.length();

    vector<pair<char, int>> p;
    for (int j = 0; j < n; j++) {
        int index = find(p, word[j]);

        if (index != -1) {
            p[index].second++;
        }
        else {
            p.push_back(make_pair(word[j], 1));
        }
    }

    for (int i = 0; i < p.size(); i++) {
        string t = "";
        t += p[i].first;

        vector<pair<char, int>> s = p;
        s[find(s, t[0])].second--;

        process(t, s);
    }

    cout << cnt;

    return 0;
}
