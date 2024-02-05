#include <iostream>
#include <algorithm>
#include <cmath>
#include <numeric>

using namespace std;

int n, m;
long long max_num = 0;
long long* nums;

bool is_valid_length(long long height){
    if(height < 0) return false; 
    
    long long count = 0;

    for(int i = 0; i < n; i++){
        if(nums[i]-height  > 0) count += nums[i]-height;
    }

    if(count >= m) return true;
    return false;
}

void parametric_search(){   
    sort(nums, nums+n); 

    long long height;
    long long left = 0; //height can be 0
    long long right = nums[n-1];
    long long res = 1;
    
    // similar to binary search
    while(left <= right){
        height = (left+right)/2;

        if(is_valid_length(height)){ //여기서 param check (different from binary search)
            res = height;
            left = height+1; //increase the height by 1
        }
        else{
            right = height-1; //decrease the height by 1
        }
    }

    cout << res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    nums = (long long*)malloc(n*sizeof(long long));
    for(int i = 0; i < n; ++i){
        cin >> nums[i];
    }

    parametric_search();
    
    return 0;
}