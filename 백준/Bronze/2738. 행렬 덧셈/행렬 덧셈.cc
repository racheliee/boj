#include <bits/stdc++.h>
#define endl '\n'
#define MAXNUM 101

using namespace std;

int n, m;
int m1[MAXNUM][MAXNUM];
int m2[MAXNUM][MAXNUM];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;

    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            cin >> m1[i][j];
        }
    }

    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            cin >> m2[i][j];
        }
    }


    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            cout << m1[i][j] + m2[i][j] << ' ';
        }
        cout << endl;
    }

}