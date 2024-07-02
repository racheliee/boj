#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

#define MAXNUM 26

int n;
int board[MAXNUM][MAXNUM];  // given board
int visited[MAXNUM][MAXNUM];
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
queue<pair<int, int>> q;
int house_num = 2; // start from 2 to distinguish from 1
vector<int> cluster_sizes;

int not_oob(int nx, int ny){
    return nx >= 0 && nx < n && ny >= 0 && ny < n;
}

void bfs(int x, int y) {
    q.push({x, y});
    board[x][y] = house_num;
    int cnt = 1;

    int nx, ny;
    while(!q.empty()){
        auto cur = q.front();
        q.pop();
        
        for(int i = 0; i < 4; ++i){
            nx = cur.first + dx[i];
            ny = cur.second + dy[i];

            if(not_oob(nx, ny) && board[nx][ny] == 1){
                board[nx][ny] = house_num;
                q.push({nx, ny});
                cnt++;
            }
        }
    }

    house_num++;
    cluster_sizes.push_back(cnt);
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    for(int i = 0; i < n; ++i){
        string temp;
        cin >> temp;
        for(int j = 0; j < n; ++j){
            board[i][j] = temp[j] - '0';
        }
    }

    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            if(board[i][j] == 1)
                bfs(i, j);
        }
    }

    cout << house_num-2 << endl;

    sort(cluster_sizes.begin(), cluster_sizes.end());
    for(int itr: cluster_sizes){
        cout << itr << endl;
    }

    return 0;
}