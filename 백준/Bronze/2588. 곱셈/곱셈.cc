#include <algorithm>
#include <cmath>
#include <deque>
#include <iostream>
#include <string.h>
#include <string>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n; string m;
    cin >> n >> m;

    for(int i = m.length()-1; i >= 0; i--){
        cout << n*(m[i]-'0') << endl;
    }

    cout << n*stoi(m);
    

}