#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int arr[246913] = {0}; //size = 123456*2+1 & initialized to 0

// bool is_prime(long long x){
//     if(x == 1 || x == 0) return false;

//     long long i = 2;
//     while(i*i <= x){ //completes in O(sqrt(n))
//         if(x % i == 0) return false;
//         i++;
//     }

//     return true;
// }

int main(){
    // cin, cout 속도 향상
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    //mark non-prime numbers as 1
    arr[1] = 1;
    for(int i = 2; i <= 246913; i++){
        if(arr[i] == 1) continue;
        //clear off all multiples
        for(int j = i*2; j <= 246913; j+=i){
            arr[j] = 1;
        }
    }

    int n;
    cin >> n;
    
    while(n != 0){
        int prime_count = 0;

        for(int i = n+1; i <= 2*n; i++){
            prime_count = arr[i] == 0 ? prime_count + 1 : prime_count;
        }

        cin >> n;
        cout << prime_count << "\n";
    }

    return 0;
}