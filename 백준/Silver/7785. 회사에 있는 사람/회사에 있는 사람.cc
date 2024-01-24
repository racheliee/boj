#include <iostream>
#include <algorithm>
#include <string>
#include <map>

using namespace std;

int main(){
    // cin, cout 속도 향상
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    map<string, int, greater<string> > google;

    for(int i = 0; i < n; i++){
        string name, log;
        cin >> name >> log; 

        if(log[0] == 'e'){ //user entered
            google[name] = 1;
        }else{
            google.erase(name); //delete if left
        }
    }

    // print
    for(auto it = google.begin(); it != google.end(); ++it){
        if(it->second){
            cout << it->first << "\n";
        }
    }

    return 0;
}