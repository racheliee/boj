#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <deque>
#include <string.h>
#include <numeric>
#include <queue>
#include <iomanip>

using namespace std; 

void print(){
    string eqn;
    cin >> eqn;

    int ans = 0;
    int length = eqn.length();
    bool minus_ahead = false; //since eqn starts w a number
    string num;
    for(int i = 0; i < length; i++){
        if(eqn[i] == '-' || eqn[i] == '+'){
            if(minus_ahead) ans -= stoi(num);
            else ans += stoi(num);
            num.clear();
        }else{ 
            num += eqn[i];
        }

        //minus appears --> just subtract all following numbers
        if(eqn[i] == '-') minus_ahead = true;
    } 

    if(minus_ahead) ans -= stoi(num);
    else ans += stoi(num);

    cout << ans;
        
    return;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    print();

    return 0;
}