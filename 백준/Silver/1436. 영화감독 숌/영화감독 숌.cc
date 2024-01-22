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

    int num = 665;
    while(n > 0){
        num++;
        string num_str = to_string(num);

        for(int i = 0; i < num_str.length()-2; i++){
            if((num_str[i]-'0') == 6 && (num_str[i+1]-'0') == 6 && (num_str[i+2]-'0') == 6){
                n--;
                break;
            }
        }
    }

    cout << num;

    return 0;
}