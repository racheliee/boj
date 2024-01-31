#include <iostream>

using namespace std; 

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n;

    int mi = 1000001, ma = -1000001;;
    
    for(int i = 0; i < n; i++){
        cin >> m;
        if(m > ma) ma = m;
        if(m < mi) mi = m;
    }

    cout << mi << " " << ma;
}