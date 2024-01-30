#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    unordered_map<string, bool> dancing;

    string first, second;
    while(n){
        n--;
        
        cin >> first >> second;

        if(first == "ChongChong"){
            dancing[first] = true;
        }else if(second == "ChongChong"){
            dancing[second] = true;
        }
        
        if(dancing[first]){
            dancing[second] = true;
        }else if(dancing[second]){
            dancing[first] = true;
        }
    }

    int count = 0;
    for(auto keys: dancing){
        if(keys.second) count++;
    }
    cout << count ;

    return 0;
}