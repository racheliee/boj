#include <iostream>
#include <algorithm>
#include <string>
#include <list>

using namespace std;

// if x coordinate (first) is the same, compare y coordinates
bool compare(const string a, const string b){
    if(a.length() != b.length()){
        return a.length() < b.length();
    }else{
        return a < b; //returns 1 is string a is alphabetically less than b
    }

}
int main(){
    // cin, cout 속도 향상
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    vector<string> str(n);

    for(int i = 0; i < n; i++){
        string temp;
        cin >> temp;
        str[i] = temp;
    }

    sort(str.begin(), str.end(), compare);

    cout << str[0] << "\n";
    for(int i = 1; i < n; i++){
        if(str[i] != str[i-1]){
            cout << str[i] << "\n";
        }
    }

    return 0;
}