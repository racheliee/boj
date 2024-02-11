#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

int res[9];
int n, m;

void backTrack(int index){
    if(index == m){
        for(int i = 0; i < m; i++){
            cout << res[i] << " ";
        }
        cout << endl;
        return;
    }

    for(int i = 1; i <=n; i++){
        if((index == 0 || res[index-1] <= i)){ //not used (false)
            res[index] = i;
            backTrack(index+1);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;

    backTrack(0);

    return 0;
}