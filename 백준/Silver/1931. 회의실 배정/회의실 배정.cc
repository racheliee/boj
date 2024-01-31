#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <deque>
#include <string.h>
#include <numeric>

using namespace std; 

bool compare(const pair<int, int> a, const pair<int, int> b){
    if(a.second == b.second) return a.first < b.first;
    return a.second < b.second;
}

void coins(){
    int n;
    cin >> n;

    vector<pair<int, int> > meetings(n); //start time, finish times

    for(int i = 0; i < n; i++){
        cin >> meetings[i].first >> meetings[i].second;
    }
    
    sort(meetings.begin(), meetings.end(), compare);

    int num_meetings = 1;
    int finish_time = meetings[0].second;

    for(int i = 1; i < n; i++){
        if(meetings[i].first >= finish_time){
            num_meetings++;
            finish_time = meetings[i].second;
        }
    }

    cout << num_meetings;
    return;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    coins();

    return 0;
}