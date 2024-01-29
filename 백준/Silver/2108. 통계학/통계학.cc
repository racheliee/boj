#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    vector<int> v(n);
    double sum = 0;
    for(int i = 0; i < n; i++){
        cin >> v[i];
        sum += v[i];
    }

    sort(v.begin(), v.end());

    unordered_map<int, int> map;
    for(int i = 0; i < n; i++){
        map[v[i]]++;
    }
    vector<pair<int, int>> freq(map.begin(), map.end());
    sort(freq.begin(), freq.end(), [](const pair<int, int> a, const pair<int, int> b){
        if(a.second == b.second){
            return a.first < b.first;
        }
        return a.second > b.second;
    });

    int avg = round(sum/n);
    cout << avg << "\n"; //average
    cout << v[n/2] << "\n"; //median
    int third = freq[0].second != freq[1].second ? freq[0].first : freq[1].first;
    cout << third << "\n"; //second smallest with largest frequency
    cout << v[n-1]-v[0]; //range

    return 0;
}