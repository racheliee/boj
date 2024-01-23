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

    string phonecall;
    cin >> phonecall;

    int seconds[26] = { 3, 3, 3, 4, 4, 4, 5, 5, 5, 6, 6, 6, 7, 7, 7, 8, 8, 8, 8, 9, 9, 9, 10, 10, 10, 10 };
    int time = 0;
    for(int i = 0; i < phonecall.length(); i++){
        time += seconds[phonecall[i] - 'A'];
    }

    cout << time;

    return 0;
}