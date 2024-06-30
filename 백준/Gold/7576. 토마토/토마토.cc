#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

#define MAXNUM 1001

int n, m;
int tomatoes[MAXNUM][MAXNUM] = {0};
int dx[] = {-1, 1, 0, 0}; // up, down, left, right
int dy[] = {0, 0, -1, 1};
queue<pair<int, int>> q;
int fresh_tomatoes = 0;

bool is_within_bound(int nx, int ny) {
    return nx >= 0 && nx < n && ny >= 0 && ny < m;
}

int bfs() {
    int x, y;

    while (!q.empty()) {
        x = q.front().first;
        y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (is_within_bound(nx, ny) && tomatoes[nx][ny] == 0) {
                tomatoes[nx][ny] = tomatoes[x][y] + 1;
                q.push({nx, ny});
                fresh_tomatoes--;
            }
        }
    }

    return fresh_tomatoes == 0 ? tomatoes[x][y] -1 : -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> m >> n;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> tomatoes[i][j];
            if (tomatoes[i][j] == 1) {
                q.push({i, j}); // push all the starting rotten tomatoes
            } else if (tomatoes[i][j] == 0) {
                fresh_tomatoes++; // count number of fresh tomatoes
            }
        }
    }

    if(fresh_tomatoes == 0) { // if no fresh tomatoes, return 0 days
        cout << 0;
        return 0; 
    }

    cout << bfs();

    return 0;
}