#include <iostream>
#include <algorithm>
#include <string>
#include <set>

using namespace std;

int main(){
    // cin, cout 속도 향상
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string n;
    cin >> n;

    char alphabet = 'a';
    while(alphabet <= 'z'){
        bool included = false;

        for(int i = 0; i < n.length(); i++){
            if(n[i] == alphabet){
                included = true;
                cout << i << " ";
                break;
            }
        }

        if(!included){
            cout << -1 << " ";
        }

        alphabet++;
    }

    return 0;
}