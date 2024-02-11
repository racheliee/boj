#include <bits/stdc++.h>
#define endl '\n'

using namespace std;
using ll = long long;

int n, c;
vector<long long> weights;

//meet in the middle algorithm
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> c;
    weights.resize(n);
    
    for(int i = 0; i < n; i++) cin >> weights[i];

    //returns all possible subset sums from left to right
    //[] = lambda func, (int, int) = params, -> indicates return type
    auto subsets_sums = [](int left, int right) -> vector<ll>{
        ll total = 1 << (right-left+1); //bc there are 2^n subsets; bitmasking
        ll sum;
        vector<ll> v;

        for(int i = 0; i < total; i++){
            sum = 0;
            for(int j = 0; j < n; j++){
                //jth element 
                if(i & (1 << j)) sum += weights[left+j];
            }
            v.push_back(sum);
        }

        return v;
    };

    vector<ll> a = subsets_sums(0, n/2-1);
    vector<ll> b = subsets_sums(n/2, n-1);

    sort(b.begin(), b.end()); //sort the left half

    ll ans = 0;
    for(auto x: a){
        //if a is in the set, check how many of b can fit the knapsack (c-x)
        ans += upper_bound(b.begin(), b.end(), c-x) - b.begin();
    }

    cout << ans;

    return 0;
}