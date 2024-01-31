#include <iostream>
#include <algorithm>

using namespace std; 

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    int num;
    int min_v = 1000001;
    int max_v = -1000001;
    while(n){
        n--;
        cin >> num;
        min_v = min(num, min_v);
        max_v = max(num, max_v);
    }

    cout << min_v << " " << max_v;
}