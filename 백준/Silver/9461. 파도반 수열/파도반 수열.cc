#include <bits/stdc++.h>
#define endl '\n'

using namespace std;
using lli = long long int;

int t, n;
lli dp[101];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> t;

    // set initial values
    dp[1] = 1; dp[2] = 1; dp[3] = 1; dp[4] = 2; dp[5] = 2;

    while(t--){
        cin >> n;
        for(int i = 6; i <= n; i++){
            dp[i] = dp[i-1] + dp[i-5];
        }
        cout << dp[n] << endl;
    }

    return 0;
}