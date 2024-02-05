#include <iostream>
#include <algorithm>
#include <cmath>
#include <numeric>

using namespace std;

int nums[1000001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }

    sort(nums, nums+n);

    cin >> m;

    int temp;
    for(int i = 0; i < m ; i++){
        cin >> temp;
        cout << binary_search(nums, nums+n, temp) << "\n";
    }
    
    return 0;
}