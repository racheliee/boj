#include <bits/stdc++.h>
#define endl '\n'

using namespace std;
using lli = long long int;

int n, k;
int dp[101][1000001];
int weights[1000001];
int vals[1000001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> k;

    int w, v;
    for (int i = 1; i <= n; i++) {
        cin >> weights[i] >> vals[i];
    }
    
    for (int i = 1; i <= n; i++) {
        for (w = 1; w <= k; w++) {
            if (weights[i] <= w) {
                dp[i][w] = max(dp[i-1][w], dp[i-1][w-weights[i]] + vals[i]);
            }else{
                dp[i][w] = dp[i-1][w];
            }
        }
    }

    cout << dp[n][k];

    return 0;
}