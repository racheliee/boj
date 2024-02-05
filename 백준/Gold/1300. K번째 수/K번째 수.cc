#include <bits/stdc++.h>
#define endl

using namespace std;

int n, k;

bool is_valid_num(int mid){
    int count = 0;

    for(int i = 1; i <= n; i++){
        count += min(mid/i, n); // since each row is i*1, *2, *3, ...
    }                           // mid/i will be the num of smaller elements

    if(count >= k) return true;
    else return false;
}

void parametric_search(){ 
    long long int res;
    long long int mid;
    long long int left = k; // since k >= B[k]
    long long int right = 1;

    while(right <= left){
        mid = (right+left)/2;

        if(is_valid_num(mid)){
            res = mid;
            left = mid-1; //we can go lower
        }else{
            right = mid+1; //we can go higher
        }
    }

    cout << res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> k;
    
    parametric_search();

    return 0;
}