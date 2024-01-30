#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <unordered_set>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    vector<int> factors(n);

    for(int i = 0; i < n; i++){
        cin >> factors[i];
    }

    sort(factors.begin(), factors.end());

    if(n == 1){
        cout << factors[0]* factors[0];
    }else{
        cout << factors[0] * factors[n-1];  
    }

    
    
    return 0;
}