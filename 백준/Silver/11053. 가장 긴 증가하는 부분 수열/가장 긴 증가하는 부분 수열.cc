#include <bits/stdc++.h>
#define endl '\n'

using namespace std;
using lli = long long int;

int n;
int nums[1001];
int dp[1001];

void solve(){
    for(int i = n-1; i >= 0; i--){
        for(int j = i; j < n; j++){
            if(nums[j] > nums[i]){
                dp[i] = max(dp[i], 1+dp[j]);
            }
        }
    }

    int max_v = INT_MIN;
    for(int i = 0; i < n; i++){
        if(max_v < dp[i]) max_v = dp[i];
    }

    cout << max_v+1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }

    solve();

    return 0;
}