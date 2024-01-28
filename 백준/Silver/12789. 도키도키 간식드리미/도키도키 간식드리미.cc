#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>

using namespace std;

string can_eat(){
    int n;
    cin >> n;

    int last_in = 1;
    int num;

    stack<int> one_person;

    while(n){
        n--;
        cin >> num;
        if(num == last_in){
            last_in++;
        }else{
            one_person.push(num);
        }

        while(!one_person.empty() && one_person.top()==last_in){
            one_person.pop();
            last_in++;
        }
    }

    if(one_person.empty()){
        return "Nice";
    }else{
        return "Sad";
    }
}

int main(){
    // cin, cout 속도 향상s
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cout << can_eat();

    return 0;
}