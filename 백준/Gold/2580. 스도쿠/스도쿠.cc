#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

int sudoku[9][9];
vector<pair<int, int>> coor;
int num = 0;
bool solution = false;

bool is_valid(int index, int val) {
    for (int i = 0; i < 9; i++) {
        //check cols
        if (i != coor[index].second && sudoku[coor[index].first][i] == val) {
            return false;
        }
        //check rows
        if (i != coor[index].first && sudoku[i][coor[index].second] == val) {
            return false;
        }
    }

    // check square
    for (int i = coor[index].first / 3 * 3; i < coor[index].first / 3 * 3 + 3; i++) {
        for (int j = coor[index].second / 3 * 3; j < coor[index].second / 3 * 3 + 3; j++) {
            if (i != coor[index].first && j != coor[index].second && sudoku[i][j] == val) {
                return false;
            }
        }
    }

    return true;
}

void backTrack(int index) {
    if (index == num) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                cout << sudoku[i][j] << " ";
            }
            cout << endl;
        }
        solution = true; //a solution was found so flag is changed
        return;
    }

    for (int i = 1; i <= 9; i++) {
        sudoku[coor[index].first][coor[index].second] = i;

        if (is_valid(index, i)) {
            backTrack(index + 1);
        }

        if(solution){
            return;
        }
    }

    sudoku[coor[index].first][coor[index].second] = 0;
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cin >> sudoku[i][j];
            if (sudoku[i][j] == 0) {
                coor.push_back({i, j});
                num++;
            }
        }
    }

    backTrack(0);

    return 0;
}