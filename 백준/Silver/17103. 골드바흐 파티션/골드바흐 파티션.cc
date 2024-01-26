#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

#define MAX 1000000

int arr[MAX+1] = {0}; //initialized to 0

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

    //eratosthenes method
    //mark non-prime numbers as 1
    arr[1] = 1;
    for(int i = 2; i <= MAX; i++){
        if(arr[i] == 1) continue;
        //clear off all multiples
        for(int j = i*2; j <= MAX; j+=i){
            arr[j] = 1;
        }
    }

    int n;
    cin >> n;

    int num, conjecture_count;
    for(int i = 0; i < n; i++){
        cin >> num;
        conjecture_count = 0;

        for(int j = 2; j < num/2+1; j++){
            conjecture_count = (!arr[j] && !arr[num-j]) ? conjecture_count + 1 : conjecture_count;
        }

        cout << conjecture_count << "\n";
    }
   

    return 0;
}