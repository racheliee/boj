#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main(){
    // cin, cout 속도 향상
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    scanf("%d", &n);


    int min = 99999;
    for(int i = 0; i < 1700; i++){
        for(int j = 0; j < 1001; j++){
            if(3*i + 5*j == n && i+j < min){
                min = i+j;
            }
        }
    }

    if(min == 99999){
        cout << -1;
    }else{
        cout << min;
    }

    return 0;
}