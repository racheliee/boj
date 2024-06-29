#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

int n, m; // map dimensions
int x, y; // current coordinates
int k;    // number of commands
vector<vector<int>> coordinate;
vector<int> dice(6, 0); // 0: top, 1: bottom, 2: north, 3: south, 4: west, 5: east

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // get input
    cin >> n >> m >> x >> y >> k;
    coordinate.resize(n, vector<int>(m, 0));

    // fill map
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            cin >> coordinate[i][j];
    }

    // get commands
    // 1: east, 2: west, 3: north, 4: south
    while (k--) {
        int command;
        cin >> command;

        // check if the command is within range
        if (command == 1 && y + 1 >= m)
            continue;
        if (command == 2 && y - 1 < 0)
            continue;
        if (command == 3 && x - 1 < 0)
            continue;
        if (command == 4 && x + 1 >= n)
            continue;

        // roll dice
        switch (command) {
        case 1:
            y++;
            dice = {dice[4], dice[5], dice[2], dice[3], dice[1], dice[0]};
            break;
        case 2:
            y--;
            dice = {dice[5], dice[4], dice[2], dice[3], dice[0], dice[1]};
            break;
        case 3:
            x--;
            dice = {dice[3], dice[2], dice[0], dice[1], dice[4], dice[5]};
            break;
        case 4:
            x++;
            dice = {dice[2], dice[3], dice[1], dice[0], dice[4], dice[5]};
            break;
        }

        if (!coordinate[x][y])
            coordinate[x][y] = dice[1];
        else {
            dice[1] = coordinate[x][y];
            coordinate[x][y] = 0;
        }

        cout << dice[0] << endl;
    }

    return 0;
}