#include <algorithm>
#include <cmath>
#include <deque>
#include <iostream>
#include <string.h>
#include <string>
#include <vector>

using namespace std;

void stars(int x, int y, int n) {
    if((x/n)%3 == 1 && (y/n)%3 == 1) { //middle is filled w space
        cout << ' ';
        return;
    }else{ //otherwise fill with recursion
        if(n / 3 == 0){
            cout << "*";
        }else{
            stars(x, y, n/3);
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            stars(i, j, n);
        }
        cout << "\n";
    }
}