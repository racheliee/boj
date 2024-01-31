#include <iostream>

using namespace std; 

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    int num;
    int min = 1000001;
    int max = -1000001;
    for(int i = 0; i < n; i++){
        cin >> num;
        min = num < min ? num : min;
        max = num > max ? num : max;
    }

    cout << min << " " << max;
}