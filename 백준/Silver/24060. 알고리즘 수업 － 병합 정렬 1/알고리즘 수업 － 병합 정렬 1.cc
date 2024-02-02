#include <algorithm>
#include <cmath>
#include <deque>
#include <iostream>
#include <string.h>
#include <string>
#include <vector>

using namespace std;

int temp[500001];
int count = 0;

void merge(int* arr, int p, int q, int r, int* k){
    int i = p;
    int j = q+1;
    int t = 1;
    
    while (i <= q && j <= r){
        if(arr[i] <= arr[j]){
            temp[t++] = arr[i++];
        }else{
            temp[t++] = arr[j++];
        }
    }

    while(i <= q){
        temp[t++] = arr[i++];
    }
    while(j <= r){
        temp[t++] = arr[j++];
    }

    i = p; t = 1;
    while(i <= r){
        arr[i++] = temp[t++];
        *k -= 1;
        if(*k == 0) cout << arr[i-1];
    }
}

void merge_sort(int* arr, int p, int r, int* k){
    if(p < r){
        int q = floor((p+r)/2);
        merge_sort(arr, p, q, k);
        merge_sort(arr, q+1, r, k);
        merge(arr, p, q, r, k);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, k;
    cin >> n >> k;

    int arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    merge_sort(arr, 0, n-1, &k);
    
    if(k > 0){
        cout << -1;
    }

}