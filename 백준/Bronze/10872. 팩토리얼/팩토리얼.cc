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

    int n;
    cin >> n;

    int num = 1;
    for(int i = 2; i <= n; i++){
        num *= i;
    }

    if(n == 0) num = 1;

    cout << num;
    return 0;
}