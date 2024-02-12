#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

int n, temp;
vector<int> nums;
vector<int> opers(4);
int max_v = INT_MIN;
int min_v = INT_MAX;

void backTrack(int res, int index) {
    if (index == n) {
        if(res < min_v) min_v = res;
        if(res > max_v) max_v = res;
        return;
    }

    for (int i = 0; i < 4; i++) {
        if(opers[i] > 0){
            opers[i]--;
            
            if(i == 0){
                backTrack(res + nums[index], index+1);
            }else if (i == 1){
                backTrack(res - nums[index], index+1);
            }else if(i == 2){
                backTrack(res * nums[index], index+1);
            }else{
                backTrack(res / nums[index], index+1);
            }

            opers[i]++;
        }
    }

    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> temp;
        nums.push_back(temp);
    }

    for(int i = 0; i < 4; i++){
        cin >> opers[i];
    }

    backTrack(nums[0], 1);
    cout << max_v << endl << min_v;

    return 0;
}