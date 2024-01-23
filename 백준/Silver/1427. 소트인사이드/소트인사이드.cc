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
    cin >> n;

    string n_str = to_string(n);

    vector<int> nums(n_str.length());

    for(int i = 0; i < n_str.length(); i++){
        nums[i] = n_str[i] - '0';
    }

    sort(nums.begin(), nums.end(), greater<int>());

    for(int i = 0; i < n_str.length(); i++){
        cout << nums[i];
    }

    return 0;
}