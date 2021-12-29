#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

string generate_sentences(vector<string> dictionary, string sentences) {
    queue<string> nouns;
    queue<string> commands;
    queue<string> verbs;
    queue<string> adjectives;
    queue<string> adverbs;
    queue<string> prepositions;

    for (int i = 0; i < dictionary.size(); i++) {
        dictionary[i] += ' ';

        string tmp = "";
        if (dictionary[i][0] == 'N') {
            for (int j = 2; j < dictionary[i].length(); j++) {
                tmp += dictionary[i][j];

                if (dictionary[i][j + 1] == ' ') {
                    nouns.push(tmp);
                    tmp = "";
                    j++;
                    continue;
                }
            }
        } else if (dictionary[i][0] == 'C') {
            for (int j = 2; j < dictionary[i].length(); j++) {
                tmp += dictionary[i][j];

                if (dictionary[i][j + 1] == ' ') {
                    commands.push(tmp);
                    tmp = "";
                    j++;
                    continue;
                }
            }
        } else if (dictionary[i][0] == 'V') {
            for (int j = 2; j < dictionary[i].length(); j++) {
                tmp += dictionary[i][j];

                if (dictionary[i][j + 1] == ' ') {
                    verbs.push(tmp);
                    tmp = "";
                    j++;
                    continue;
                }
            }
        } else if (dictionary[i][0] == 'J') {
            for (int j = 2; j < dictionary[i].length(); j++) {
                tmp += dictionary[i][j];

                if (dictionary[i][j + 1] == ' ') {
                    adjectives.push(tmp);
                    tmp = "";
                    j++;
                    continue;
                }
            }
        } else if (dictionary[i][0] == 'B') {
            for (int j = 2; j < dictionary[i].length(); j++) {
                tmp += dictionary[i][j];

                if (dictionary[i][j + 1] == ' ') {
                    adverbs.push(tmp);
                    tmp = "";
                    j++;
                    continue;
                }
            }
        } else if (dictionary[i][0] == 'P') {
            for (int j = 2; j < dictionary[i].length(); j++) {
                tmp += dictionary[i][j];

                if (dictionary[i][j + 1] == ' ') {
                    prepositions.push(tmp);
                    tmp = "";
                    j++;
                    continue;
                }
            }
        }
    }

    string sentence;
    char cur = sentences[0];

    if (cur == 'Q') {
        sentence += "What ";
    }

    sentences += ' ';

    for (int i = 1; i < sentences.length(); i++) {
        string word;

        if (sentences[i] == 'N') {
            word = nouns.front();
            nouns.pop();
            nouns.push(word);

            sentence += word + " ";
        } else if (sentences[i] == 'C') {
            word = commands.front();
            commands.pop();
            commands.push(word);

            sentence += word + " ";
        } else if (sentences[i] == 'V') {
            word = verbs.front();
            verbs.pop();
            verbs.push(word);

            sentence += word + " ";
        } else if (sentences[i] == 'J') {
            word = adjectives.front();
            adjectives.pop();
            adjectives.push(word);

            sentence += word + " ";
        } else if (sentences[i] == 'B') {
            word = adverbs.front();
            adverbs.pop();
            adverbs.push(word);

            sentence += word + " ";
        } else if (sentences[i] == 'P') {
            word = prepositions.front();
            prepositions.pop();
            prepositions.push(word);

            sentence += word + " ";
        } else if (sentences[i] == 'A') {
            if (sentences[i + 1] == 'N') {
                word = nouns.front();
            } else if (sentences[i + 1] == 'C') {
                word = commands.front();
            } else if (sentences[i + 1] == 'V') {
                word = verbs.front();
            } else if (sentences[i + 1] == 'J') {
                word = adjectives.front();
            } else if (sentences[i + 1] == 'B') {
                word = adverbs.front();
            } else if (sentences[i + 1] == 'P') {
                word = prepositions.front();
            }

            if (word[0] == 'a' || word[0] == 'e' || word[0] == 'i' || word[0] == 'o' || word[0] == 'u') {
                word = "an";
            } else {
                word = "a";
            }

            sentence += word + " ";
        } else if (sentences[i] == 'T') {
            word = "the";

            sentence += word + " ";
        }

        if (sentences[i + 1] == ' ') {
            if (cur == 'D') {
                sentence[sentence.length() - 1] = '.';
            } else if (cur == 'I') {
                sentence[sentence.length() - 1] = '.';
            } else if (cur == 'Q') {
                sentence[sentence.length() - 1] = '?';
            } else if (cur == 'E') {
                sentence[sentence.length() - 1] = '!';
            }
            sentence += ' ';

            cur = sentences[i + 2];

            if (cur == 'Q') {
                sentence += "What";
            }

            i += 2;
        }
    }

    return sentence;
}

int main() {
    int n;
    vector<string> dictionary;
    string sentences;
    string trash;

    cin >> n;
    getline(cin, trash);

    dictionary.resize(n);

    for (int i = 0; i < n; i++) {
        getline(cin, dictionary[i]);
    }

    getline(cin, sentences);

    cout << generate_sentences(dictionary, sentences);

    return 0;
}
