#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>

using namespace std;

string is_vps(string vps){
    stack<int> stack; //LIFO

    for(int i = 0; i < vps.length(); i++){
        if(vps[i] == '('){
            stack.push(1);
        }else{
            if(stack.empty()) {
                return "NO\n";
                continue;
            }else{
                stack.pop();
            }
        }
    }

    if(stack.empty()){
        return "YES\n";
    }else{
        return "NO\n";
    }
}

int main(){
    // cin, cout 속도 향상s
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    string vps;
    while(n){
        n--;
        cin >> vps;
        cout << is_vps(vps);
    }
    
    return 0;
}