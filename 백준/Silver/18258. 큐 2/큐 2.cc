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

    int n; string cmd;
    cin >> n;

    queue<int> queue;
    while(n){
        n--;

        cin >> cmd;

        if(cmd[1] == 'u'){ //push
            int num;
            cin >> num;
            queue.push(num);
        }else if(cmd[1] == 'o'){ //pop
            if(queue.empty()) {
                cout << -1 << "\n";
            }else{
                cout << queue.front() << "\n";
                queue.pop();
            }
        }else if(cmd[1] == 'i'){ //size
            cout << queue.size() << "\n";
        }else if(cmd[1] == 'm'){ //empty
            if(queue.empty()) {
                cout << 1 << "\n";
            }else{
                cout << 0 << "\n";
            }
        }else if(cmd[1] == 'r'){ //front
            if(queue.empty()) {
                cout << -1 << "\n";
            }else{
                cout << queue.front() << "\n";
            }
        }else if(cmd[1] == 'a'){ //back
            if(queue.empty()) {
                cout << -1 << "\n";
            }else{
                cout << queue.back() << "\n";
            }
        }
    }
    
    return 0;
}