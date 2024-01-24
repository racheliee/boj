#include <iostream>
#include <algorithm>
#include <string>
#include <map>

using namespace std;

int main(){
    // cin, cout 속도 향상
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    unordered_map<int, int> cards;

    for(int i = 0; i < n; i++){
        int card;
        cin >> card;

        if(cards.find(card) == cards.end()){
            cards[card] = 1;
        }else{
            cards[card]++;
        }
    }

    int m;
    cin >> m;

    for(int i = 0; i < m; i++){
        int given;
        cin >> given;
        
        if(cards.find(given) == cards.end()){
            cout << 0 << " ";
        }else{
            cout << cards[given] << " ";
        }
    }

    return 0;
}