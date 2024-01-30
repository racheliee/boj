#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <unordered_set>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    unordered_set<string> members;

    string entered;
    int count = 0;
    while(n){
        n--;
        
        cin >> entered;

        if(entered == "ENTER"){
            count += members.size();
            members = unordered_set<string>(); //members.clear() takes a lot of time
            continue;
        }else {
            members.insert(entered);
        }
    }

    count += members.size();

    cout << count;
    return 0;
}