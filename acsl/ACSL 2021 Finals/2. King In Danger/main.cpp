#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool board[8][8];
vector<pair<int, int>> pieces_pos;
pair<int, int> king_pos;

bool check(int x, int y) {
    for (int i = 0; i < pieces_pos.size(); i++) {
        if (x == pieces_pos[i].first && y == pieces_pos[i].second) {
            return true;
        }
    }

    return false;
}

string find_king_status(string pieces) {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            board[i][j] = false;
        }
    }

    for (int i = 0; i < pieces.length(); i += 4) {
        pieces_pos.emplace_back(make_pair(pieces[i + 1] - 'a', pieces[i + 2] - '1'));
    }

    for (int i = 0; i < pieces.length(); i += 4) {
        int x, y;
        bool north, south, west, east, north_west, north_east, south_west, south_east;
        north = south = west = east = north_west = north_east = south_west = south_east = true;

        if (pieces[i] == 'Q') {
            x = pieces[i + 1] - 'a';
            y = pieces[i + 2] - '1';

            for (int j = 1; j < 8; j++) {
                if (y + j < 8 && north) {
                    board[x][y + j] = true;

                    if (check(x, y + j)) {
                        north = false;
                    }
                }

                if (y - j >= 0 && south) {
                    board[x][y - j] = true;

                    if (check(x, y - j)) {
                        south = false;
                    }
                }

                if (x + j < 8 && west) {
                    board[x + j][y] = true;

                    if (check(x + j, y)) {
                        west = false;
                    }
                }

                if (x - j >= 0 && east) {
                    board[x - j][y] = true;

                    if (check(x - j, y)) {
                        east = false;
                    }
                }

                if (x + j < 8 && y + j < 8 && north_west) {
                    board[x + j][y + j] = true;

                    if (check(x + j, y + j)) {
                        north_west = false;
                    }
                }

                if (x + j < 8 && y - j >= 0 && south_west) {
                    board[x + j][y - j] = true;

                    if (check(x + j, y - j)) {
                        south_west = false;
                    }
                }

                if (x - j >= 0 && y + j < 8 && north_east) {
                    board[x - j][y + j] = true;

                    if (check(x - j, y + j)) {
                        north_east = false;
                    }
                }

                if (x - j >= 0 && y - j >= 0 && south_east) {
                    board[x - j][y - j] = true;

                    if (check(x - j, y - j)) {
                        south_east = false;
                    }
                }
            }
        } else if (pieces[i] == 'R') {
            x = pieces[i + 1] - 'a';
            y = pieces[i + 2] - '1';

            for (int j = 1; j < 8; j++) {
                if (y + j < 8 && north) {
                    board[x][y + j] = true;

                    if (check(x, y + j)) {
                        north = false;
                    }
                }

                if (y - j >= 0 && south) {
                    board[x][y - j] = true;

                    if (check(x, y - j)) {
                        south = false;
                    }
                }

                if (x + j < 8 && west) {
                    board[x + j][y] = true;

                    if (check(x + j, y)) {
                        west = false;
                    }
                }

                if (x - j >= 0 && east) {
                    board[x - j][y] = true;

                    if (check(x - j, y)) {
                        east = false;
                    }
                }
            }
        } else if (pieces[i] == 'B') {
            x = pieces[i + 1] - 'a';
            y = pieces[i + 2] - '1';

            for (int j = 1; j < 8; j++) {
                if (x + j < 8 && y + j < 8 && north_west) {
                    board[x + j][y + j] = true;

                    if (check(x + j, y + j)) {
                        north_west = false;
                    }
                }

                if (x + j < 8 && y - j >= 0 && south_west) {
                    board[x + j][y - j] = true;

                    if (check(x + j, y - j)) {
                        south_west = false;
                    }
                }

                if (x - j >= 0 && y + j < 8 && north_east) {
                    board[x - j][y + j] = true;

                    if (check(x - j, y + j)) {
                        north_east = false;
                    }
                }

                if (x - j >= 0 && y - j >= 0 && south_east) {
                    board[x - j][y - j] = true;

                    if (check(x - j, y - j)) {
                        south_east = false;
                    }
                }
            }
        } else if (pieces[i] == 'P') {
            x = pieces[i + 1] - 'a';
            y = pieces[i + 2] - '1';

            if (x - 1 >= 0 && y + 1 < 8) {
                board[x - 1][y + 1] = true;
            }

            if (x + 1 < 8 && y + 1 < 8) {
                board[x + 1][y + 1] = true;
            }
        } else if (pieces[i] == 'N') {
            x = pieces[i + 1] - 'a';
            y = pieces[i + 2] - '1';

            if (x + 1 < 8 && y + 2 < 8) {
                board[x + 1][y + 2] = true;
            }

            if (x + 2 < 8 && y + 1 < 8) {
                board[x + 2][y + 1] = true;
            }

            if (x + 2 < 8 && y - 1 >= 0) {
                board[x + 2][y - 1] = true;
            }

            if (x + 1 < 8 && y - 2 >= 0) {
                board[x + 1][y - 2] = true;
            }

            if (x - 1 >= 0 && y - 2 >= 0) {
                board[x - 1][y - 2] = true;
            }

            if (x - 2 >= 0 && y - 1 >= 0) {
                board[x - 2][y - 1] = true;
            }

            if (x - 2 >= 0 && y + 1 < 8) {
                board[x - 2][y + 1] = true;
            }

            if (x - 1 >= 0 && y + 2 < 8) {
                board[x - 1][y + 2] = true;
            }
        } else if (pieces[i] == 'K') {
            king_pos.first = pieces[i + 1] - 'a';
            king_pos.second = pieces[i + 2] - '1';
        }
    }


    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            cout << board[i][j] << " ";
        }

        cout << endl;
    }


    int cnt = 0;

    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            if (board[king_pos.first + i][king_pos.second + j] || (king_pos.first + i >= 8 || king_pos.first + i < 0) || (king_pos.second + j >= 8 || king_pos.second + j < 0)) {
                cnt++;
            }
        }
    }

    if (cnt == 9) {
        return "CHECKMATE";
    }

    if (cnt ==  8 && !board[king_pos.first][king_pos.second]) {
        return "STALEMATE";
    }

    if (board[king_pos.first][king_pos.second]) {
        return "CHECK";
    }

    return "SAFE";
}

int main() {
    string input = "Kh8 Ng6";

    cout << find_king_status(input);
}
