#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>

using namespace std;

string is_vps(string vps){
    stack<char> stack; //LIFO

    for(int i = 0; i < vps.length(); i++){
        if(vps[i] == '('){
            stack.push('(');
        }else if(vps[i] == ')'){
            if(stack.empty() || stack.top() != '(') {
                return "no\n";
            }
            else{
                stack.pop();
            }
        }else if(vps[i] == '['){
            stack.push('[');
        }else if(vps[i] == ']'){
            if(stack.empty() || stack.top() != '[') {
                return "no\n";
            }else{
                stack.pop();
            }
        }
    }

    if(stack.empty()){
        return "yes\n";
    }else{
        return "no\n";
    }
}

int main(){
    // cin, cout 속도 향상s
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string vps;
    while(true){
        getline(cin, vps);
        if(vps == ".") break;
        cout << is_vps(vps);
    }
    
    return 0;
}