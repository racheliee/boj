#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

bool is_prime(long long x){
    if(x == 1 || x == 0) return false;
    if(x <= 3) return true;
    if(x % 2 == 0 || x % 3 == 0) return false;

    long long i = 5;
    while(i*i <= x){ //completes in O(sqrt(n))
        if(x % i == 0 || x % (i+2) == 0) return false;
        i++;
    }

    return true;
}

int main(){
    // cin, cout 속도 향상
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int m, n;
    cin >> m >> n;
    
    if(m == 1) m++;
    if(m == 2) cout << 2 << "\n";
    m += 1-m%2;
    for(int i = m; i <= n; i+=2){ 
        if(is_prime(i)){
            cout << i << "\n";
        }
    }

    return 0;
}