#include <iostream>
#include <algorithm>
#include <string>
#include <set>

using namespace std;

int main(){
    // cin, cout 속도 향상
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    set<string> s;
    vector<string> check(m);

    for(int i = 0; i < n; i++){
        string str;
        cin >> str;
        s.insert(str);
    }

    for(int i = 0; i < m; i++){
        cin >> check[i]; 
    }

    int num = 0;
    for(int i = 0; i < m; i++){
        num = s.find(check[i]) != s.end() ? num+1 : num;
    }

    cout << num;

    return 0;
}