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

void treasure(){
    int n;
    cin >> n;

    vector<int> a(n);
    vector<int> b(n);

    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cin >> b[i];

    sort(a.begin(), a.end());
    sort(b.begin(), b.end(), greater<int>());

    int sum = 0;
    for(int i = 0; i < n; i++){
        sum += a[i]*b[i];
    }

    cout << sum;
    
    return;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    treasure();

    return 0;
}