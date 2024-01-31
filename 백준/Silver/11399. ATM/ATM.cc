#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <deque>
#include <string.h>
#include <numeric>

using namespace std; 

void ATM(){
    int n;
    cin >> n;

    vector<int> line(n);
    for(int i = 0; i < n; i++){
        cin >> line[i];
    }

    sort(line.begin(), line.end());

    for(int i = 1; i < n; i++){
        line[i] += line[i-1];
    }

    int sum = accumulate(line.begin(), line.end(), 0);
    cout << sum;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ATM();

    return 0;
}