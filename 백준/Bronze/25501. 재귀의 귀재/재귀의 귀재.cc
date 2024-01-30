#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <unordered_set>
#include <string.h>

using namespace std; 

int recursion(const char* s, int l, int r, int* count){
    *count += 1;
    if(l >= r) return 1;
    else if(s[l] != s[r]) return 0;
    else return recursion(s, l+1, r-1, count);
}

int isPalindrome(const char* s, int* count){
    return recursion(s, 0, strlen(s)-1, count);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    string str; //char*은 시작 주소를 넘기기 떄문에 더 빠르다
    while(n){
        n--;

        cin >> str;
        int count = 0;
        // .c_str() changes string to const char*
        cout << isPalindrome(str.c_str(), &count) << " " << count << "\n";
    }
    
}