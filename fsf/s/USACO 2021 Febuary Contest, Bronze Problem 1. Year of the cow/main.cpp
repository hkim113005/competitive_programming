#include <iostream>
#include <tuple>

using namespace std;

int N;
tuple<string, int, int> cows[105];
int cow_len = 1;

int get_num(string s) {
    if (s == "Ox") {
        return 1;
    }
    else if (s == "Tiger") {
        return 2;
    }
    else if (s == "Rabbit") {
        return 3;
    }
    else if (s == "Dragon") {
        return 4;
    }
    else if (s == "Snake") {
        return 5;
    }
    else if (s == "Horse") {
        return 6;
    }
    else if (s == "Goat") {
        return 7;
    }
    else if (s == "Monkey") {
        return 8;
    }
    else if (s == "Rooster") {
        return 9;
    }
    else if (s == "Dog") {
        return 10;
    }
    else if (s == "Pig") {
        return 11;
    }
    else if (s == "Rat") {
        return 12;
    }
}

int get_index(string s) {
    for (int i = 0; i < cow_len; i++) {
        if (s == get<0>(cows[i])) {
            return i;
        }
    }

    cow_len++;

    return cow_len - 1;
}

int main() {
    cin >> N;

    get<0>(cows[0]) = "Bessie";
    get<1>(cows[0]) = 1;
    get<2>(cows[0]) = 0;

    for (int i = 0; i < N; i++) {
        string t;
        string name1;
        string name2;
        string act;
        string animal;

        cin >> name1 >> t >> t >> act >> animal >> t >> t >> name2;

        if (act == "previous") {
            int a = get<1>(cows[get_index(name2)]);
            int b = get_num(animal);

            int c;

            if (b > a) {
                c = (b - a) - 12;
            }
            else if (b < a) {
                c = b - a;
            }
            else {
                c = -12;
            }

            int d = get_index(name1);
            int e = get_index(name2);

            get<0>(cows[d]) = name1;
            get<1>(cows[d]) = b;
            get<2>(cows[d]) = get<2>(cows[e]) + c;
        }
        else if (act == "next") {
            int a = get<1>(cows[get_index(name2)]);
            int b = get_num(animal);

            int c;

            if (b < a) {
                c = (b - a) + 12;
            }
            else if (b > a) {
                c = b - a;
            }
            else {
                c = 12;
            }

            int d = get_index(name1);
            int e = get_index(name2);

            get<0>(cows[d]) = name1;
            get<1>(cows[d]) = b;
            get<2>(cows[d]) = get<2>(cows[e]) + c;
        }
    }

    cout << abs(get<2>(cows[get_index("Elsie")]));

    return 0;
}
