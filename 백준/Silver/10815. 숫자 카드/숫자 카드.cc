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

    int n;
    cin >> n;

    set<int> my_cards;
    for(int i = 0; i < n; i++){
        int temp;
        cin >> temp;
        my_cards.insert(temp);
    }

    int m;
    cin >> m;

    vector<int> cards(m);

    for(int i = 0; i < m; i++){
        cin >> cards[i];
    }
    
    //c++20 has a 'contains' function but we asre using c++17
    for(int i = 0; i < m; i++){
        int in_set = my_cards.find(cards[i]) != my_cards.end() ? 1 : 0;
        cout << in_set << " ";
    }

    return 0;
}