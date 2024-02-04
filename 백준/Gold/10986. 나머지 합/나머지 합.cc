#include <iostream>
#include <algorithm>
#include <cmath>
#include <numeric>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<long long int> s(n);
    unordered_map<long long int, long long int> mod(m); // PrefixSum[j] - PrefixSum[i] ) % MOD = 0 이 만족한다면
                                    // PrefixSum[j] % MOD = PrefixSum[i] % MOD 도 만족하게 된다.

    cin >> s[0];
    mod[s[0]%m]++;
    for(size_t i = 1; i < n; i++){
        cin >> s[i];
        s[i] += s[i-1];
        mod[s[i] % m]++;
    }

    //prefix_sum%MOD = 0 이 되는 것들의 의미는 첫 번째 원소부터 i번째까지의 누적합이 MOD로 나누어 떨어진다는 의미
    //PrefixSum[j] % MOD = PrefixSum[i] % MOD의 갯수 n, 그 중에 2개씩 뽑기
    long long int count = mod[0];
    for(size_t i = 0; i < m; i++){
        long long int t = mod[i];
        count += (t*(t-1))/2; //nC2
    }
    
    cout << count;
    return 0;
}