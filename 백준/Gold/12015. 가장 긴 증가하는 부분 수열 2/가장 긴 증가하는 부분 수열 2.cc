#include <iostream>
#include <algorithm>
#include <cmath>
#include <numeric>
#include <limits.h>

using namespace std;

int n;
long long nums[10000000];

int lis_length(){ //using binary search not dp
    vector<int> a;

    a.push_back(nums[0]);
    for(int i = 1; i < n; ++i){
        if(nums[i] > a.back()){
            // if larger, append at the back
            a.push_back(nums[i]);
        }else{
            //binary search to find smallest element that is greater or equal to curr num
            //lower_bound returns that number
            int lower = lower_bound(a.begin(), a.end(), nums[i]) - a.begin();
            a[lower] = nums[i];
        }
    }

    return a.size();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    
    for(int i = 0; i < n; ++i){
        cin >> nums[i];
    }
    
    cout << lis_length();

    return 0;
}
