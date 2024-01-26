#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int main(){
    // cin, cout 속도 향상
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // 창문이 열려있기 위해서는 --> 열고 닫는 횟수가 홀수
    // 약수가 홀수개 --> 제곱수
    // 제곱수는 소인수 분해 --> 소인수의 지수가 모두 짝수개 --> 공식: (짝수+1)(짝수+1)... = 홀수    
    int n;
    cin >> n;

    int i = 1;
    while (n >= i*i){
        i++;
    }
    
    cout << i-1;

    return 0;
}