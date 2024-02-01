#include <algorithm>
#include <cmath>
#include <deque>
#include <iostream>
#include <string.h>
#include <string>
#include <vector>

using namespace std;

void cantorian_set(int n) {
    if(n == 0) {
        cout << '-';
        return;
    }

    int size = pow(3, n-1);

    cantorian_set(n-1);
    for(int i = 0; i < size; i++){
        cout << ' ';
    }
    cantorian_set(n-1);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    while(cin >> n){
        cantorian_set(n);
        cout << "\n";
    }
}