#include <iostream>
#include <algorithm>
#include <string>
#include <set>

using namespace std;

int reverse(int a){
    string str = to_string(a);
    reverse(str.begin(), str.end());
    return stoi(str);
}

int main(){
    // cin, cout 속도 향상
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n;
    cin >> m;

    n = reverse(n);
    m = reverse(m);

    int output = n > m? n: m;
    cout << output;

    return 0;
}