#include <iostream>
#include <algorithm>
#include <string>
#include <set>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int a, b, v;
    cin >> a;
    cin >> b;
    cin >> v;

    int days = (v-a) % (a-b);

    if(days % (a-b) == 0){
        days = (v-a) / (a-b) + 1;
    }else{
        days = (v-a) / (a-b) + 2;
    }

    cout << days;
    return 0;
}