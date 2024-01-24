#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <list>

using namespace std;

int main(){
    // cin, cout 속도 향상
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    unordered_map<string, int> not_heard;
    list<string> neither;

    for(int i = 0; i < n; i++){
        string name;
        cin >> name;

        not_heard[name] = 1;
    }

    int index = 0;
    for(int i = 0; i < m; i++){
        string name;
        cin >> name;

        if(not_heard.find(name) != not_heard.end()){
            neither.push_back(name);
            index++;
        }
    }

    cout << index << "\n";
    neither.sort();
    for(auto i : neither){
        cout << i << "\n";
    }

    return 0;
}