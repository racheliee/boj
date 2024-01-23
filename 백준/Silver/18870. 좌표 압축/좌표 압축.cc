#include <iostream>
#include <algorithm>
#include <string>
#include <tuple>

using namespace std;

bool compare_coordinates(const tuple<int, int, int>& a, const tuple<int, int, int>& b){
    return get<0>(a) < get<0>(b);
}

bool compare_index(const tuple<int, int, int>& a, const tuple<int, int, int>& b){
    return get<1>(a) < get<1>(b);
}

int main(){
    // cin, cout 속도 향상
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    // <coordinate, og index, compressed index>
    vector<tuple<int, int, int> > nums(n);

    for(int i = 0; i < n; i++){
        int num;
        cin >> num;

        nums[i] = tuple<int, int, int>(num, i, 0);
    }

    sort(nums.begin(), nums.end(), compare_coordinates);

    int new_coor = 1;
    for(int i = 1; i < n; i++){
        new_coor = get<0>(nums[i]) == get<0>(nums[i-1]) ? new_coor-1: new_coor;
        get<2>(nums[i]) = new_coor;
        new_coor++;
    }

    sort(nums.begin(), nums.end(), compare_index);

    for(int i = 0; i < n; i++){
        cout << get<2>(nums[i]) << " ";
    }

    return 0;
}