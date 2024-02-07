#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int a, b;
    cin >> a >> b;

    if(a > b) cout << ">";
    else if(a < b) cout << "<";
    else cout << "==";

}