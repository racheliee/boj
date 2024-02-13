#include <bits/stdc++.h>
#define endl '\n'

using namespace std;
using lli = long long int;

int n;
int dp[100001];

void solve(){
    //use kadane's algo
    
    int max_v = INT_MIN;
    int curr_max = 0;
    for(int i = 0;i < n; i++){
        curr_max += dp[i];
        if(curr_max > max_v) max_v = curr_max;
        if(curr_max < 0) curr_max = 0;
    }

    cout << max_v;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n ;

    for(int i = 0; i < n; i++){
        cin >> dp[i];
    }

    solve();

    return 0;
}