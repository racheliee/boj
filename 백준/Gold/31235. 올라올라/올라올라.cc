#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

int arr[1000001];
int n;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    int temp = 1, k = 1;  
    int anchor = arr[0];
    for(int i = 1; i < n; i++){
        // if the next num is less than the previous one, 
        // increase k (we need to increase it until a larger number is found)
        if(arr[i] < anchor){
            k++;
        }
        // if it is not decreasing, save the larger value between temp and k, and reset k
        // if another decreasing portion is found, it will be saved into a new k
        // and compared with temp again
        else{
            temp = max(temp, k);
            k = 1; // reset k
            anchor = arr[i]; // set the new anchor
        }
    }

    cout << max(temp, k);

    return 0;
}