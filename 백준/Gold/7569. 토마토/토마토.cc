#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

#define MAXNUM 101

int n, m, h;
int tomatoes[MAXNUM][MAXNUM][MAXNUM];
int dx[] = {-1, 1, 0, 0, 0, 0};
int dy[] = {0, 0, -1, 1, 0, 0};
int dz[] = {0, 0, 0, 0, -1, 1};
queue<tuple<int, int, int>> q;
int fresh_tomatoes = 0;

bool is_within_bound(int nx, int ny, int nz) {
    return nx >= 0 && nx < n && ny >= 0 && ny < m && nz >= 0 && nz < h;
}

int bfs() {
    int x, y, z;

    while (!q.empty()) {
        z = get<0>(q.front());
        x = get<1>(q.front());
        y = get<2>(q.front());
        q.pop();

        for (int i = 0; i < 6; ++i) {
            int nz = z + dz[i];
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (is_within_bound(nx, ny, nz) && tomatoes[nz][nx][ny] == 0) {
                tomatoes[nz][nx][ny] = tomatoes[z][x][y] + 1;
                q.push({nz, nx, ny});
                fresh_tomatoes--;
            }
        }
    }

    return fresh_tomatoes == 0 ? tomatoes[z][x][y] - 1 : -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> m >> n >> h;

    for (int k = 0; k < h; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cin >> tomatoes[k][i][j];
                if (tomatoes[k][i][j] == 1) {
                    q.push({k, i, j}); // push all the starting rotten tomatoes
                } else if (tomatoes[k][i][j] == 0) {
                    fresh_tomatoes++; // count number of fresh tomatoes
                }
            }
        }
    }

    if (fresh_tomatoes == 0) { // if no fresh tomatoes, return 0 days
        cout << 0;
        return 0;
    }

    cout << bfs();

    return 0;
}