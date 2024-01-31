#include <iostream>

using namespace std; 

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, num;
    cin >> n;

    int min_v = 1000001;
    int max_v = -1000001;
    
    while(n){
        n--;
        cin >> num;
        if(num > max_v) max_v = num;
        if(num < min_v) min_v = num;
    }

    cout << min_v << " " << max_v;
}