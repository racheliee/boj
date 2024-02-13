#include <bits/stdc++.h>
#define endl '\n'

using namespace std;
using lli = long long int;

int n;
int dp[10000001];

void solve(){
    dp[1] = 0;

    for(int i = 2; i <= n; i++){
        dp[i] = dp[i-1] + 1;
        if(i%3 == 0){
            dp[i] = min(dp[i/3] + 1, dp[i]);
        }
        if(i%2 == 0){
            dp[i] = min(dp[i/2] + 1, dp[i]);
        }
    }

    cout << dp[n];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    solve();

    return 0;
}