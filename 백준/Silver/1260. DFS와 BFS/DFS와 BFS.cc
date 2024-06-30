#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

int n, m, v;
int graph[1001][1001] = {0};
bool visited[1001] = {false};

void dfs(int node){
    visited[node] = true;
    cout << node << " ";

    for(int i = 1; i <= n; ++i){
        if(graph[node][i] && !visited[i] && i != node){
            dfs(i);
        }
    }
}

void bfs(){
    memset(visited, false, sizeof(visited));
    queue<int> q;
    q.push(v);
    visited[v] = true;

    while(!q.empty()){
        int node = q.front();
        cout << node << " ";
        q.pop();

        for(int i = 1; i <= n; ++i){
            if(graph[node][i] && !visited[i] && i != node){
                visited[i] = true;
                q.push(i);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m >> v;

    int a, b;
    for(int i = 0; i < m; i++){
        cin >> a >> b;
        graph[a][b] = 1;
        graph[b][a] = 1;
    }

    dfs(v);
    cout << endl;
    bfs();

    return 0;
}