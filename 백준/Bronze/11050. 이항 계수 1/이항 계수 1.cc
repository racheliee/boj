#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, k;
    cin >> n >> k;

    int num = 1;

    if(n == 0) num = 1;
    else{
        for(int i = k+1; i <= n; i++){
            num *= i;
        }
    }

    int dom = 1;
    if(dom == 0) dom = 1;
    else{
        for(int i = 2; i <= n-k; i++){
            dom *= i;
        }
    }

    cout << num/dom;
    return 0;
}