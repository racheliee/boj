#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>

using namespace std;

int main(){
    // cin, cout 속도 향상s
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, num;
    cin >> n;

    stack<int> stack; //LIFO

    while(n){
        n--;

        cin >> num;

        if(num != 0){
            stack.push(num);
        }else{
            stack.pop();
        }
    }

    int sum = 0;
    while(!stack.empty()){
        sum += stack.top();
        stack.pop();
    }

    cout << sum;
    
    return 0;
}