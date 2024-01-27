#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <list>

using namespace std;

int main(){
    // cin, cout 속도 향상
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, cmd;
    cin >> n;

    list<int> stack; //LIFO

    while(n){
        n--;

        cin >> cmd;

        if(cmd == 1){
            int num;
            cin >> num;

            stack.push_back(num);
        }else if (cmd == 2){
            if(stack.empty()){
                cout << -1 << "\n";
            }else{
                cout << stack.back() << "\n";
                stack.pop_back();
            }
        }else if (cmd == 3){
            cout << stack.size() << "\n";
        }else if (cmd == 4){
            int empty = stack.empty() ? 1 : 0;
            cout << empty << "\n";
        }else{
            if(stack.empty()){
                cout << -1 << "\n";
            }else{
                cout << stack.back() << "\n";
            }
        }
        
    }
    

    return 0;
}