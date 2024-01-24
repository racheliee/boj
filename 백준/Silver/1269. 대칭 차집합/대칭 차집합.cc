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

    set<int> a;
    set<int> b;

    for(int i = 0; i < n; i++) {
        int num;
        cin >> num;
        a.insert(num);
    }
    for(int i = 0; i < m; i++){
        int num;
        cin >> num;
        b.insert(num);
    }

    vector<int> common;
    set_intersection(a.begin(), a.end(), b.begin(), b.end(), back_inserter(common));

    cout << a.size()+b.size()-2*common.size();

    return 0;
}