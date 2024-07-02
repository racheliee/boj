#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

#define MAXNUM 101

int n, m;
int computers[MAXNUM][MAXNUM];  // given computers
int visited[MAXNUM] = {0};
queue<int> q;
int infected = 0;

void bfs() {
    q.push(0); // starts with computer 1;
    visited[0] = 1;

    while (!q.empty()) {
       int cur = q.front();
       q.pop();

        for(int i = 0; i < n; ++i){
            if(computers[cur][i] && !visited[i]){
                infected++;
                visited[i] = 1;
                q.push(i);
            }
        }
    }

}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;

    int a, b;
    while(m--){
        cin >> a >> b;

        computers[--a][--b] = 1;
        computers[b][a] = 1;
    }

    bfs();

    cout << infected;

    return 0;
}