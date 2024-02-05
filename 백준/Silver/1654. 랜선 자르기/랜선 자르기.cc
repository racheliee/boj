#include <iostream>
#include <algorithm>
#include <cmath>
#include <numeric>

using namespace std;

int k, n;
long long max_num = 0;
long long nums[1000000];

bool is_valid_length(long long m){
    long long count = 0;

    for(int i = 0; i < k; ++i){
        count += nums[i]/m;
        if(count >= n) return true;
    }

    return false;
}

void parametric_search(){
    long long mid;
    long long left = 1; //랜선의길이 must be at least 1
    long long right = max_num;
    long long res = 1;
    
    // similar to binary search
    while(left <= right){
        mid = (left+right)/2;

        if(is_valid_length(mid)){ //여기서 param check (different from binary search)
            res = res < mid ? mid : res;
            left = mid+1; //increase the length by 1
        }
        else{
            right = mid-1; //decrease the length by 1
        }
    }

    cout << res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> k >> n;

    for(int i = 0; i < k; ++i){
        cin >> nums[i];
        if(max_num < nums[i]) max_num = nums[i]; //don't sort, just get the max
    }

    parametric_search();
    
    return 0;
}