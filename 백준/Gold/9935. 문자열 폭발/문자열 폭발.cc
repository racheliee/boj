#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string str, bomb, t;
    cin >> str >> bomb;

    int s_len = str.length();
    int b_len = bomb.length();

    stack<char> s;

    for(int i = 0; i < s_len; i++){
        s.push(str[i]);

        if(s.top() == bomb[b_len-1] && s.size() >= b_len){
            t = "";
            for(int j = 0; j < b_len; j++){
                t += s.top();
                s.pop();
            }

            reverse(t.begin(), t.end());

            if(t != bomb){
                for(int j = 0; j < b_len; j++){
                    s.push(t[j]);
                }
            }
        }
    }

    if(s.empty()) cout << "FRULA";
    else{
        t = "";
        while(!s.empty()){
            t += s.top();
            s.pop();
        }

        for(int i = t.length()-1; i >= 0; i--){
            cout << t[i];
        }
    }

    return 0;
}