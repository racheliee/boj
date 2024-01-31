#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <deque>
#include <string.h>
#include <numeric>

using namespace std; 

void coins(){
    int n, k;
    cin >> n >> k;

    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    int num_coins = 0;
    for(int i = n-1; i > -1; i--){
        while(k-arr[i] >= 0){
            k -= arr[i];
            num_coins++;
        }
    }

    cout << num_coins;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    coins();

    return 0;
}