#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <list>

using namespace std;

int main(){
    // cin, cout 속도 향상s
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, cmd; 
    cin >> n;

    list<int> deck;
    while(n){
        n--;

        cin >> cmd;

        switch(cmd){
            int num;
            case 1:
                cin >> num;
                deck.push_front(num);
                break;
            case 2:
                cin >> num;
                deck.push_back(num);
                break;
            case 3:
                if(deck.empty()) {
                    cout << -1 << "\n";
                }else{
                    cout << deck.front() << "\n";
                    deck.pop_front();
                }
                break;
            case 4:
                if(deck.empty()) {
                    cout << -1 << "\n";
                }else{
                    cout << deck.back() << "\n";
                    deck.pop_back();
                }
                break;
            case 5:
                cout << deck.size() << "\n";
                break;
            case 6:
                num = deck.empty() ? 1 : 0;
                cout << num << "\n";
                break;
            case 7:
                num = deck.empty() ? -1 : deck.front();
                cout << num << "\n";
                break;
            case 8:
                num = deck.empty() ? -1 : deck.back();
                cout << num << "\n";
                break;
            default:
                continue;
        }
    }
    
    return 0;
}