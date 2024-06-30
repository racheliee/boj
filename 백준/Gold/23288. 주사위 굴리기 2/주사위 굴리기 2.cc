#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

int n, m, k;      // map dimensions, number of commands
int x = 0, y = 0; // current coordinates
vector<vector<int>> coordinate;
vector<vector<bool>> visited;
vector<int> dice = {1, 6, 2, 5, 4, 3}; // 0: top, 1: bottom, 2: north, 3: south, 4: west, 5: east
int direction = 0;                     // 0: east, 1: south, 2: west, 3: north
int score = 0;
int dy[] = {0, 1, 0, -1};
int dx[] = {1, 0, -1, 0};

void check_bounds() {
    int nx = x + dx[direction];
    int ny = y + dy[direction];

    if (nx < 0 || nx >= m || ny < 0 || ny >= n) {
        direction = (direction + 2) % 4; // reverse direction
        ny = y + dy[direction];
        nx = x + dx[direction];
    }

    y = ny;
    x = nx;
    // printf("y: %d, x: %d\n", y, x);
}

void roll_dice() {
    switch (direction) {
    case 0: // east
        dice = {dice[4], dice[5], dice[2], dice[3], dice[1], dice[0]};
        break;
    case 1: // south
        dice = {dice[2], dice[3], dice[1], dice[0], dice[4], dice[5]};
        break;
    case 2: // west
        dice = {dice[5], dice[4], dice[2], dice[3], dice[0], dice[1]};
        break;
    case 3: // north
        dice = {dice[3], dice[2], dice[0], dice[1], dice[4], dice[5]};
        break;
    }
}

void update_dir() {
    if (coordinate[y][x] < dice[1]) { // clockwise 90 degrees
        direction = (direction + 1) % 4;
    } else if (coordinate[y][x] > dice[1]) { // counterclockwise 90 degrees

        direction = (direction + 4 - 1) % 4;
    }
}

void find_esnw() {
    // reset visited vector
    for (int i = 0; i < n; i++)
        fill(visited[i].begin(), visited[i].end(), false);

    int num = coordinate[y][x];
    int count = 1; // num of cells we can continuously visit

    queue<pair<int, int>> q;
    q.push({y, x});
    visited[y][x] = true;

    while (!q.empty()) {
        int cy = q.front().first;
        int cx = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];

            if (nx < 0 || nx >= m || ny < 0 || ny >= n)
                continue;
            if (visited[ny][nx])
                continue;
            visited[ny][nx] = true;

            if (coordinate[ny][nx] != num)
                continue;

            count++;
            q.push({ny, nx});
        }
    }

    // printf("count: %d, num: %d\n", count, num);

    score += count * num;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // get input
    cin >> n >> m >> k;
    coordinate.resize(n, vector<int>(m, 0));
    visited.resize(n, vector<bool>(m, false));

    // fill map
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            cin >> coordinate[i][j];
    }

    while (k--) {
        check_bounds(); // check if we can move
        roll_dice();    // move the dice
        update_dir();   // update direction
        find_esnw();    // find cells with the same number and add to score
    }

    cout << score;

    return 0;
}