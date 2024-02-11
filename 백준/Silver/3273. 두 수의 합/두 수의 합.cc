#include <iostream>
#include <algorithm>
#include <cmath>
#include <limits.h>

using namespace std; 

int n, m;
vector<int> arr;

void closestPair(){
    cin >> n;
    arr.resize(n);
    
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    cin >> m;

    sort(arr.begin(), arr.end());

    int i = 0; int j = n-1;
    int distance;
    int pairs = 0;

    while (i < j){
        distance = abs(arr[i] + arr[j]);

        if(distance == m){
            pairs++;
        }
        //pointers need to move towards each other
        if(arr[i] + arr[j] < m){ //if their sum is less than m, i needs to increase for a bigger sum
            i++;
        }else{
            j--;
        }
    }
    
    cout << pairs;
    return;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    closestPair();

    return 0;
}