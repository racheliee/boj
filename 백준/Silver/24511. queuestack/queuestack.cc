#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <deque>

using namespace std; 

int q_or_st[100000];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    deque<int> dq;

    for(int i = 0; i < n; i++){
        cin >> q_or_st[i]; // queue = 0, stack = 1
    }

    int num;
    for(int i = 0; i < n; i++){
        cin >> num;
        if(!q_or_st[i]){
            dq.push_back(num); //only queue elements need to be saved
        }                      //stack the popped and push element is the same
    }

    int m;
    cin >> m;

    while(m){
        m--;
        cin >> num;

        dq.push_front(num); //new element goes to the front
        cout << dq.back() << " ";
        dq.pop_back(); // the last element would be popped
    }
    
}