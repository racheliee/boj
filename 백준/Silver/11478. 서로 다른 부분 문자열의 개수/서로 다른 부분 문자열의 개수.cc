#include <iostream>
#include <algorithm>
#include <string>
#include <unordered_set>

using namespace std;

int main(){
    // cin, cout 속도 향상
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string str;
    cin >> str;

    unordered_set<string> substr;

    int length = str.length();
    for(int i = 1; i <= length; i++){ //i = length
        for(int j = 0; j < length-i+1; j++){ //j = start index
            //substring in c++ is string.substr(start index, length)
            substr.insert(str.substr(j, i));
        }
    }

    cout << substr.size();

    return 0;
}