#include <bits/stdc++.h>
#define endl '\n'

using namespace std;
using lli = long long int;

int n;
int dp[301];
int price[301];
int max_p = INT_MIN;

void solve(){
    dp[0] = price[0]; //first step
    dp[1] = price[0] + price[1]; // first step + second step
    dp[2] = max(price[0] + price[2], price[1] + price[2]); // one step vs two step

    for(int i = 3; i < n; i++){
        dp[i] = max(dp[i-2] + price[i], dp[i-3] + price[i-1] + price[i]);
    }

    cout << dp[n-1];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> price[i];
    }

    solve();

    return 0;
}