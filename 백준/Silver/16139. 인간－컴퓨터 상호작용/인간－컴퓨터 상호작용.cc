#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

string str;
int q, l, r, sum;
char a;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> str >> q;

    while(q--){
        cin >> a >> l >> r;
        sum = 0;
        for(int i = l; i <= r; i++){
            if(str[i] == a){
                sum++;
            }
        }
        cout << sum << endl;
    }


    return 0;
}