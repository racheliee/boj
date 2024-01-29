#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<int> nums(n+1);
    nums[0] = 0;
    for(int i = 1; i <= n; i++){
        cin >> nums[i];
        nums[i] += nums[i-1]; //array of subsequent sums
    }

    int i, j;
    while(m){
        m--;

        cin >> i >> j;
        i--;
        cout << nums[j]-nums[i] << "\n";
    }
    
    return 0;
}