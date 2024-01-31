#include <iostream>
#include <algorithm>
#include <cmath>
#include <limits.h>

using namespace std; 

void closestPair(){
    int n;
    cin >> n;

    vector<int> arr(n);
    
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());

    int min_distance = INT_MAX;
    int one; int two;

    int i = 0; int j = n-1;
    int distance;

    while (i < j){
        distance = abs(arr[i] + arr[j]);

        if(distance == 0){
            cout << arr[i] << " " << arr[j];
            return;
        }

        if(distance < min_distance){
            min_distance = distance;
            one = arr[i]; two = arr[j];
        }

        //pointers need to move towards each other
        if(abs(arr[i]) < abs(arr[j])){ //arr[i] is negative, j-- will reduce arr[j], potentially bringing it closer to 0
            j--;
        }else{
            i++;
        }
    }
    
    cout << one << " " << two;
    return;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    closestPair();

    return 0;
}