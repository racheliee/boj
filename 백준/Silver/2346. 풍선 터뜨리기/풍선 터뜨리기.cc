#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <deque>

using namespace std;

int main(){
    // cin, cout 속도 향상s
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    deque<pair<int, int> > balloons; //double ended queue
    
    for(int i = 0; i < n; i++){
        int nums;
        cin >> nums;
        balloons.push_back(pair<int, int>(i+1, nums));
    }


    while(!balloons.empty()){
        int k = balloons.front().second; //the kth element will be at the front now, print it
        cout << balloons.front().first << " ";
        balloons.pop_front();

        if(k > 0){
            for(int i = 0; i < k-1; i++){ // k-1 is needed here bc it counts starting 1,2,3...
                balloons.push_back(balloons.front());
                balloons.pop_front();
            }
        }else{
            for(int i = 0; i < k*-1; i++){ //k-1 is not needed here
                balloons.push_front(balloons.back());
                balloons.pop_back();
            }
        }
    }

    

    return 0;
}