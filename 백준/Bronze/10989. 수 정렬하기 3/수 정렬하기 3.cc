#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main(){
    // cin, cout 속도 향상
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    int num;
    vector<int> count_arr(10001, 0);
    for(int i = 0; i < n; i++){
        cin >> num;
        count_arr[num]++;
    }
    
    for(int i = 0; i < 10001; i++){
        for(int j = 0; j < count_arr[i]; j++){
            cout << i << "\n";
        }
    }

    return 0;
}