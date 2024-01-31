#include <iostream>

using namespace std; 

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    int num;
    int min_v = 1000001;
    int max_v = -1000001;
    
    for(size_t i = 0; i < n; i++){
        cin >> num;
        if(num > max_v) max_v = num;
        if(num < min_v) min_v = num;
    }

    cout << min_v << " " << max_v;
}