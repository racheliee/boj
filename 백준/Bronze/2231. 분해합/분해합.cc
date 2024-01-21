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

    for(int i = 0; i < n; i++){
        string str = to_string(i);
        int sum = i;

        for(int j = 0; j < str.length(); j++){
            sum += (str[j] - '0');
        }

        if(sum == n){
            cout << i;
            return 0;
        }
    }
    
    cout << 0;
    return 0;
}