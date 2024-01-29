#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int main(){
    // cin, cout 속도 향상s
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, k;
    cin >> n >> k;

    queue<int> josh;
    k--;
    for(int i = 1; i <= n; i++){
        josh.push(i);
    }

    cout << "<";
    while(n && josh.size() != 1){
        n--;
        
        int temp;
        for(int i = 0; i < k; i++){ //if under k, then just move it to the end of the q
            if(!josh.empty()){
                josh.push(josh.front());
                josh.pop();
            }
        }

        cout << josh.front() << ", "; //the kth element will be at the front now, print it
        josh.pop();
    }

    cout << josh.front() << ">";

    return 0;
}