#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    // cin, cout 속도 향상
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;

    scanf("%d %d", &n, &m);

    int nums[n];

    for(int i = 0; i < n; i++){
        scanf("%d", &nums[i]);
    }

    int max = 0;

    for(int i = 0; i < n; i ++){
        for(int j = i+1; j < n; j++){
            for(int k = j+1; k < n; k++){
                if(nums[i] + nums[j] + nums[k] <= m && nums[i] + nums[j] + nums[k] > max){
                    max = nums[i] + nums[j] + nums[k];
                }
            }
        }
    }

    printf("%d", max);

    return 0;
}