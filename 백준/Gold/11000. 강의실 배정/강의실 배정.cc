#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <deque>
#include <string.h>
#include <numeric>
#include <queue>

using namespace std; 

void classes(){
    int n;
    cin >> n;

    vector<pair<int, int> > v(n);
    priority_queue<int, vector<int>, greater<int> > pq; //min heap

    for(int i = 0; i < n; i++){
        cin >> v[i].first >> v[i].second;
    }

    sort(v.begin(), v.end());

    pq.push(v[0].second);
    for(int i = 1; i < n; i++){     
        if(v[i].first >= pq.top()){ //if the next class time is after the end time, pop the existing element since they can be done in the same time
            pq.pop();
        }
        pq.push(v[i].second);   
    }
    
    cout << pq.size();
    return;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    classes();

    return 0;
}