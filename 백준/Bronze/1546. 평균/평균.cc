#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <deque>
#include <string.h>
#include <numeric>
#include <queue>
#include <iomanip>

using namespace std; 

void print(){
    int n;
    cin >> n;

    vector<double> scores(n);
    double max = 0;
    for(int i = 0; i < n; i++){
        cin >> scores[i];
        if(max < scores[i]) max = scores[i];
    }

    double sum = 0;
    for(int i = 0; i < n; i++){
        sum += scores[i] / max * 100;
    }
    cout << setprecision(20) << sum/n;
        
    return;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    print();

    return 0;
}