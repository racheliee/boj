#include <bits/stdc++.h>
#define endl '\n'

using namespace std;
using lli = long long int;

int n;
int dp[100001][3];
int price[1001][3];
int min_p = INT_MAX;

void solve(){
    dp[1][0] = price[1][0]; //begin w red
    dp[1][1] = price[1][1]; //green
    dp[1][2] = price[1][2]; //blue

    for(int i = 2; i <= n; i++){
        for(int j = 0; j < 3; j++){
            if(j == 0){ //if curr = red, then previous house has to be green or blue
                dp[i][j] = price[i][j] + min(dp[i-1][1], dp[i-1][2]);
            }else if(j == 1){ //if curr = green, then previous house has to be red or blue
                dp[i][j] = price[i][j] + min(dp[i-1][0], dp[i-1][2]);
            }else{ //if curr = blue, then previous house has to be red or green
                dp[i][j] = price[i][j] + min(dp[i-1][0], dp[i-1][1]);
            }
        }
    }
    cout << min(min(dp[n][0], dp[n][1]), dp[n][2]);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    for(int i = 1; i <= n; i++){
        cin >> price[i][0] >> price[i][1] >> price[i][2];
    }

    solve();

    return 0;
}