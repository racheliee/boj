#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main(){
    // cin, cout 속도 향상
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    //least common multiple (LCM)
    // = a*b*c*... / greaters common divisor(GCD)
    //GCD 찾는데 euclidean algorithm 이용

    long long int x, y;
    cin >> x >> y;

    long long int a = x < y ? y : x;
    long long int b = x < y ? x : y;

    while(b != 0){
        long long int temp = b;
        b = a%b;
        a = temp;
    } 

    cout << x*y/a << "\n";
    return 0;
}