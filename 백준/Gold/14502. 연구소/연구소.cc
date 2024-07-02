#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

#define MAXNUM 11

int n, m;
int lab[MAXNUM][MAXNUM];  // given lab
int wall[MAXNUM][MAXNUM]; // where the walls are going to be
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
queue<pair<int, int>> q;
int safety = -3; // because 3 are going to become walls
int max_safety = 0;

bool is_within_bound(int nx, int ny) {
    return nx >= 0 && nx < n && ny >= 0 && ny < m;
}

void bfs() {
    int x, y;

    queue<pair<int, int>> bfs_q = q;
    int bfs_safety = safety;
    while (!bfs_q.empty()) {
        x = bfs_q.front().first;
        y = bfs_q.front().second;
        bfs_q.pop();

        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (is_within_bound(nx, ny) && wall[nx][ny] == 0) {
                wall[nx][ny] = 2; // spread the virus
                bfs_q.push({nx, ny});
                bfs_safety--;
            }
        }
    }

    max_safety = max(max_safety, bfs_safety);
}

void build_wall(int num_walls) {
    if (num_walls == 3) {
        copy(&lab[0][0], &lab[0][0] + MAXNUM * MAXNUM, &wall[0][0]);
        bfs();
        return;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (lab[i][j] != 0)
                continue;

            lab[i][j] = 1;
            build_wall(num_walls + 1);
            lab[i][j] = 0;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> lab[i][j];
            if (lab[i][j] == 2) {
                q.push({i, j}); // push all the starting virus points
            } else if (lab[i][j] == 0) {
                safety++;
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (lab[i][j] != 0)
                continue;

            lab[i][j] = 1;
            build_wall(1);
            lab[i][j] = 0;
        }
    }

    cout << max_safety << endl;

    return 0;
}