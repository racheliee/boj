#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <deque>
#include <string.h>
#include <numeric>
#include <queue>

using namespace std; 

void print(){
    int n, x;
    cin >> n >> x;

    int num;
    while(n){
        n--;
        cin >> num;
        if(num < x) cout << num << " ";
    }
        
    return;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    print();

    return 0;
}