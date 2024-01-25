#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main(){
    // cin, cout 속도 향상
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int a, b, m, n;
    cin >> a >> b >> m >> n;

    int numerator = a*n +b*m;
    int denominator = b*n;

    int gcd = numerator < denominator ? denominator : numerator;
    int rem = numerator < denominator ? numerator : denominator;

    while(rem != 0){
        int temp = rem;
        rem = gcd % rem;
        gcd = temp;
    } 
    cout << numerator / gcd << " " << denominator / gcd;
    
    return 0;
}