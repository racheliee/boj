#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int find_gcd(int x, int y){
    int a = x < y ? y : x; //gcd
    int b = x < y ? x : y;

    while(b != 0){
        int temp = b;
        b = a%b;
        a = temp;
    } 

    return a;
}

int main(){
    // cin, cout 속도 향상
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    vector<long int> nums(n);
    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }

    int distance = nums[1]-nums[0];
    for(int i = 1; i < n; i++){
        distance = find_gcd(nums[i]-nums[i-1], distance);
        if(distance == 1) break;
    }

    cout << (nums[n-1]-nums[0])/distance-n+1;
    
    return 0;
}