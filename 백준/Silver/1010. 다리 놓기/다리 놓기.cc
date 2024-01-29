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

    int t;
    cin >> t;
    
    //nCm을 구하면 됨
    //n!/((n-m)!m!)
    long long int n, m;
    while(t){
        t--;

        cin >> n >> m;
        
        int r = 1;
        int res = 1;
        for(int j = m; j > m-n; j--){
            res *= j;
            res /= r;
            r++;
        }

        cout << res << "\n";
    }

    
    return 0;
}