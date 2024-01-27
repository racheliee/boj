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

    int n; 
    cin >> n;

    queue<int> queue;
    for(int i = 1; i <= n; i++){
        queue.push(i);
    }

    while(queue.size() != 1){
        queue.pop();
        int temp = queue.front();
        queue.pop();
        queue.push(temp);
    }
    
    cout << queue.front();
    return 0;
}