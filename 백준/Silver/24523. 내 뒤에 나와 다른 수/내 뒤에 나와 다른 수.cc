#include <bits/stdc++.h>
#define endl '\n'

using namespace std;
using ll = long long int;

ll arr[1000001];
int arr2[1000001]; //saves the j indexes (answers)
int n;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    int j_idx = -1;
    for(int i = n-1; i > 0; i--){
        arr2[i] = j_idx;

        if(arr[i] != arr[i-1]){ //different numbers update j_idx
            j_idx = i+1;
        }
    }
    arr2[0] = j_idx; //last element
    
    for(int i = 0; i < n; i++){
        cout << arr2[i] << " ";
    }
    
    return 0;
}