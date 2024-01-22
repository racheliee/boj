#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main(){
    // cin, cout 속도 향상
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    scanf("%d", &n);

    int nums[n];
    for(int i = 0; i < n; i++){
        scanf("%d", &nums[i]);
    }

    sort(nums, nums+n);

    for(int i= 0; i < n; i++){
        cout << nums[i] << "\n";
    }

    return 0;
}