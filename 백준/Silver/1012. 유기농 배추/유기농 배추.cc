#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

#define MAXNUM 51

int t, m, n, k;
int board[MAXNUM][MAXNUM];  // given board
int visited[MAXNUM][MAXNUM];
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
queue<pair<int, int>> q;
int worms = 2; // to distinguish with 1

int not_oob(int nx, int ny){
    return nx >= 0 && nx < n && ny >= 0 && ny < m;
}

void bfs(int x, int y) {
    q.push({x, y});
    board[x][y] = worms;

    int nx, ny;
    while(!q.empty()){
        auto cur = q.front();
        q.pop();
        
        for(int i = 0; i < 4; ++i){
            nx = cur.first + dx[i];
            ny = cur.second + dy[i];

            if(not_oob(nx, ny) && board[nx][ny] == 1){
                board[nx][ny] = worms; // board also keeps track of visited cells
                q.push({nx, ny});
            }
        }
    }

    worms++;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> t;

    while(t--){
        // get input
        cin >> m >> n >> k;
        
        int a, b;
        memset(board, 0, sizeof(board)); // reset board
        while(k--){
            cin >> a >> b; // a represents column

            board[b][a] = 1;
        }

        // do bfs for each cluster
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < m; ++j){
                if(board[i][j] == 1)
                    bfs(i, j);
            }
        }

        cout << worms - 2 << endl;

        worms = 2;
    }
    

    return 0;
}