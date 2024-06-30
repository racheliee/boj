#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

#define MAXNUM 101

int n;
char graph[MAXNUM][MAXNUM] = {0};
int bfs_visited[MAXNUM][MAXNUM] = {0}; // keeps track of the region numbers as well
int dx[] = {-1, 1, 0, 0}; // up, down, left, right
int dy[] = {0, 0, -1, 1};


bool is_within_bound(int nx, int ny){
    return nx >= 0 && nx < n && ny >= 0 && ny < n;
}

void bfs(int og_x, int og_y, int curr_region){
    queue<pair<int, int>> q;
    q.push({og_x, og_y});
    bfs_visited[og_x][og_y] = curr_region;

    int x, y;
    while(!q.empty()){
        x = q.front().first;
        y = q.front().second;
        q.pop();

        for(int i = 0; i < 4; ++i){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(is_within_bound(nx, ny) && !bfs_visited[nx][ny] && graph[nx][ny] == graph[og_x][og_y]){
                bfs_visited[nx][ny] = true;
                q.push({nx, ny});
                bfs_visited[nx][ny] = curr_region;
            }
        }
    }
}

bool red_or_green(int og_x, int og_y, int nx, int ny) {
    char og_color = graph[og_x][og_y];
    char new_color = graph[nx][ny];

    return (new_color == og_color) || (new_color == 'G' || new_color == 'R') && (og_color == 'G' || og_color == 'R');
}


void colourblind_bfs(int og_x, int og_y, int curr_region){
    queue<pair<int, int>> q;
    q.push({og_x, og_y});
    bfs_visited[og_x][og_y] = curr_region;

    int x, y;
    while(!q.empty()){
        x = q.front().first;
        y = q.front().second;
        q.pop();

        for(int i = 0; i < 4; ++i){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(is_within_bound(nx, ny) && !bfs_visited[nx][ny] && red_or_green(og_x, og_y, nx, ny)){
                bfs_visited[nx][ny] = true;
                q.push({nx, ny});
                bfs_visited[nx][ny] = curr_region;
            }
        }
    }
}

void mark_region(){
    int curr_region = 0;

    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            if(!bfs_visited[i][j]){
                bfs(i, j, ++curr_region);
            }
        }
    }

    cout << curr_region << " ";

    curr_region = 0;
    memset(bfs_visited, false, sizeof(bfs_visited));

    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            if(!bfs_visited[i][j]){
                colourblind_bfs(i, j, ++curr_region);
            }
        }
    }

    cout << curr_region;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            cin >> graph[i][j];
        }
    }

    mark_region();

    return 0;
}