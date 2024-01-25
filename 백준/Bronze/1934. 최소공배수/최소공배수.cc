#include <iostream>
#include <algorithm>
#include <string>
#include <unordered_set>

using namespace std;

int main(){
    // cin, cout 속도 향상
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    //least common multiple (LCM)
    // = a*b*c*... / greaters common divisor(GCD)
    //GCD 찾는데 euclidean algorithm 이용

    int n;
    cin >> n;

    for(int i = 0; i < n; i++){
        int x, y;
        cin >> x >> y;

        int a = x < y ? y : x;
        int b = x < y ? x : y;

        while(b != 0){
            int temp = b;
            b = a%b;
            a = temp;
        } 

        cout << x*y/a << "\n";
    }

    return 0;
}