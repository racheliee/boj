#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

string n, m;

void lcs_length(){
    int m_len = m.length();
    int n_len = n.length();

    int c[m_len+1][n_len+1];

    for(int i = 0; i <= m_len; i++){
        for(int j = 0; j <= n_len; j++){
            if(i == 0 || j == 0){
                c[i][j] = 0;
            }else if(m[i-1] == n[j-1]){
                c[i][j] = c[i-1][j-1] + 1;
            }else{
                c[i][j] = max(c[i-1][j], c[i][j-1]);
            }
        }
    }

    cout << c[m_len][n_len];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> m >> n;

    lcs_length();

    return 0;
}