#include <iostream>
#include <string>

using namespace std;

int n, ans = 1000000000;
string dna_samples[10];
bool check[10];

string process(string sequence, string sample) {
    if (sequence.length() > sample.length()) {
        for (int i = sample.length(); i > 0; i--) {
            bool same = true;

            for (int j = 0; j < i; j++) {
                if (sequence[sequence.length() - i + j] == sample[j]) {
                    continue;
                }

                same = false;
            }

            if (same) {
                return sample.substr(i, sample.length() - 1);
            }
        }
    }
    else {
        for (int i = sequence.length(); i > 0; i--) {
            bool same = true;

            for (int j = 0; j < i; j++) {
                if (sequence[sequence.length() - i + j] == sample[j]) {
                    continue;
                }

                same = false;
            }

            if (same) {
                return sample.substr(i, sample.length() - 1);
            }
        }
    }

    return sample;
}

void dna_sequencer(string sequence, string last) {
    bool done = true;
    for (int i = 0; i < n; i++) {
        done = done && check[i];
    }
    if (done) {
        int len = sequence.length();
        if (len == 7) {
            //cout << 1;
        }
        ans = min(ans, len);
        return;
    }

    for (int i = 0; i < n; i++) {
        if (check[i]) {
            continue;
        }

        string t = process(last, dna_samples[i]);
        sequence += t;
        check[i] = true;
        dna_sequencer(sequence, dna_samples[i]);
        check[i] = false;
        for (int j = 0; j < t.length(); j++) {
            sequence.pop_back();
        }
    }
}

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> dna_samples[i];
    }

    for (int i = 0; i < n; i++) {
        string t = dna_samples[i];
        check[i] = true;
        dna_sequencer(t, t);
        check[i] = false;
    }

    //cout << process("CA", "ACTG") << endl;

    cout << ans;

    return 0;
}
