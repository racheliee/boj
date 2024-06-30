#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

#define MAXNUM 1001

int n, m;
char graph[MAXNUM][MAXNUM] = {0};
int dist[MAXNUM][MAXNUM] = {0};
bool bfs_visited[MAXNUM][MAXNUM] = {false};
int dx[] = {-1, 1, 0, 0}; // up, down, left, right
int dy[] = {0, 0, -1, 1};

void bfs(){
    queue<pair<int, int>> q;
    q.push({0, 0});
    bfs_visited[0][0] = true;
    dist[0][0] = 1;

    int x, y;
    while(!q.empty()){
        x = q.front().first;
        y = q.front().second;
        q.pop();

        for(int i = 0; i < 4; ++i){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx >= 0 && nx < n && ny >= 0 && ny < m && !bfs_visited[nx][ny] && graph[nx][ny] == '1'){
                bfs_visited[nx][ny] = true;
                q.push({nx, ny});
                dist[nx][ny] = dist[x][y] + 1;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;

    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            cin >> graph[i][j];
        }
    }

    bfs();

    cout << dist[n-1][m-1];

    return 0;
}