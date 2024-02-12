#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

int n;
int dp[1000001];

int solve(int n){
    int res;
    if(n == 0) return 0;
    else if(n == 1) return 1;
    else if(dp[n]) return dp[n];
    else return dp[n] = (solve(n-1) + solve(n-2)) % 15746; //sol(n) = sol(n-1) + sol(n-2) when converted to decimal

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    dp[0] = 0; dp[1] = 1; dp[2] = 2; // set initial values

    cout << solve(n);

    return 0;
}