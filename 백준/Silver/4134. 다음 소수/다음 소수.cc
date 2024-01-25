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

    int n;
    cin >> n;

    long long num;
    for(int i = 0; i < n; i++){
        cin >> num;

        num = (num % 2 == 0 && num != 2)? num+1 : num;
        num = (num == 1)? 2 : num;
        while(!is_prime(num)){
            num+=2;
        }
        cout << num << "\n";
    }

    return 0;
}