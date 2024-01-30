#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <unordered_set>

using namespace std;

long long int factorial(long long int n){
    if(n == 0) return 1;
    return n * factorial(n-1);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    cout << factorial(n);
    
    return 0;
}