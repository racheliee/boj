#include <iostream>
#include <algorithm>
#include <cmath>
#include <numeric>

using namespace std;

int n, c;
long long* nums;

bool is_valid_length(long long m){
    long long count = 1; //starts w 1 to include the last one
    int i = 0;
    int j = 1;
    int next_house = nums[0] + m;

    while(i < n){
        while(j < n){
            if(nums[j] >= next_house){
                count++;
                break;
            }
            j++;
        }
        i = j;
        next_house = nums[j]+m;
    }

    if(count >= c) return true;
    return false;
}

void parametric_search(){    
    sort(nums, nums+n);

    long long distance;
    long long left = 1; //distance must be at least 1
    long long right = nums[n-1];
    long long res = 1;
    
    // similar to binary search
    while(left <= right){
        distance = (left+right)/2;

        if(is_valid_length(distance)){ //여기서 param check (different from binary search)
            res = res < distance ? distance : res;
            left = distance+1; //increase the distance by 1
        }
        else{
            right = distance-1; //decrease the distance by 1
        }
    }

    cout << res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> c;
    nums = (long long*)malloc(n*sizeof(long long));
    for(int i = 0; i < n; ++i){
        cin >> nums[i];
    }

    parametric_search();
    
    return 0;
}