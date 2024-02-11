#include <bits/stdc++.h>
#define endl '\n'

using namespace std;
using ll = long long;

int n, m;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;

    vector<vector<ll>> matrix(n+1, vector<ll>(n+1));

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> matrix[i][j];
            matrix[i][j] += matrix[i-1][j] + matrix[i][j-1] - matrix[i-1][j-1];
        }
    }

    int x1, x2, y1, y2;
    while(m--){
        cin >> x1 >> y1 >> x2 >> y2;
        cout << matrix[x2][y2] - matrix[x1-1][y2] - matrix[x2][y1-1] + matrix[x1-1][y1-1] << endl;
    }


    return 0;
}