#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string str, bomb;
    cin >> str >> bomb;

    int s_len = str.length();
    int b_len = bomb.length();

    string s = "";

    for(int i = 0; i < s_len; i++){
        s += str[i];

        if(s.size() >= b_len && s[s.length()-1] == bomb[b_len-1]){
            bool is_bomb = true;

            for(int j = 0; j < b_len; j++){
                if(s[s.size()-b_len+j] != bomb[j]){
                    is_bomb = false;
                    break;
                }
            }

            if(is_bomb) s.erase(s.end()-b_len, s.end());
        }
    }

    if(s.empty()) cout << "FRULA";
    else cout << s;

    return 0;
}