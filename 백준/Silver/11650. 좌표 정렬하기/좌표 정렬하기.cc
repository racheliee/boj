#include <iostream>
#include <algorithm>
#include <string>
#include <map>

using namespace std;

// if x coordinate (first) is the same, compare y coordinates
bool compare(const pair<int, int>& a, const pair<int, int>& b){
    if(a.first != b.first){
        return a.first < b.first;
    }else{
        return a.second < b.second;
    }

}
int main(){
    // cin, cout 속도 향상
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    vector<pair<int, int> > coordinates(n); //dictionary with int and int

    for(int i = 0; i < n; i++){
        int x, y;
        cin >> x;
        cin >> y;

        coordinates[i] = pair<int, int>(x, y);
    }

    sort(coordinates.begin(), coordinates.end(), compare);

    for(int i = 0; i < n; i++){
        cout<< coordinates[i].first << " " << coordinates[i].second << "\n";
    }

    return 0;
}