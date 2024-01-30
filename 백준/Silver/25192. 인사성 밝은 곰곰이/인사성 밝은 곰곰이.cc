#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <set>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    set<string> members;

    string entered;
    int count = 0;
    while(n){
        n--;
        
        cin >> entered;

        if(entered == "ENTER"){
            count += members.size();
            members.clear();
            continue;
        }
        members.insert(entered);
    }

    count += members.size();

    cout << count;
    return 0;
}