#include <bits/stdc++.h>
#define endl '\n'

using namespace std;
using lli = long long int;

int n;
int dp[501][501];
int price[501][501];
int max_p = INT_MIN;

void solve(){
    dp[0][0] = price[0][0]; //begin w first row

    for(int i = 1; i < n; i++){
        for(int j = 0; j <= i; j++){
            if(j == 0){ //if curr = red, then previous house has to be green or blue
                dp[i][j] = price[i][j] + dp[i-1][j];
            }else if(j == i){
                dp[i][j] = price[i][j] + dp[i-1][j-1];
            }else{
                dp[i][j] = price[i][j] + max(dp[i-1][j], dp[i-1][j-1]);
            }
        }
    }

    for(int i = 0; i < n; i++){
        if(dp[n-1][i] > max_p) max_p = dp[n-1][i];
    }

    cout << max_p;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    int row_count = 1;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < row_count; j++){
            cin >> price[i][j];
        }
        row_count++;
    }

    solve();

    return 0;
}