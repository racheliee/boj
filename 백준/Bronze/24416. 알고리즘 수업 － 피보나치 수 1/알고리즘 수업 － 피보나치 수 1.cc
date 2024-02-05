#include <bits/stdc++.h>
#define endl

using namespace std;

int fib(int n, int* c1){
    if(n == 1 || n ==2 ) return 1;
    else {
        *c1 += 1;
        return (fib(n-1, c1) + fib(n-2, c1));
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n, c1 = 1;
    cin >> n;

    fib(n, &c1);

    cout << c1 << " " << n-2;

    return 0;
}