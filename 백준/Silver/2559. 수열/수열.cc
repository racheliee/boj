#include <iostream>
#include <algorithm>
#include <cmath>
#include <numeric>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, k;
    cin >> n >> k;

    vector<int> v(n);
    vector<int> sum(n);

    for(int i = 0; i < n; i++){
        cin >> v[i];
        // if(i < k) sum[0] += v[i];
    }

    sum[0] = accumulate(v.begin(), next(v.begin(), k), 0);

    int i = k;
    int j = 1;
    int l = 0;
    int max = sum[0];
    while(i < n){
        sum[j] = sum[j-1]-v[l]+ v[i]; 
        if(max < sum[j]) max = sum[j];
        i++; j++; l++;
    }

    cout << max;
    
    return 0;
}