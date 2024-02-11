#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

int n;
vector<long long> sum;

void find_primes(){
    vector<int> primes(n+1, 1);
    primes[0] = 0; primes[1] = 0;

    for(int i = 2; i <= sqrt(n); i++){
        if(primes[i] == 0) continue;
        else{
            for(int j = i*2; j <= n; j += i){
                primes[j] = 0;
            }
        }
    }

    sum.push_back(0);
    for(int i = 2; i <= n; i++){
        if(primes[i]){
            sum.push_back(sum.back() + i); //getting partial sum
        }
    }
}

void closestPair() {
    cin >> n;

    find_primes();

    int equal_n = 0;

    int i = 0;
    int j = 0;
    int series_sum;
    int size = sum.size();

    while (i <= j && j < size) {
        series_sum = sum[j] - sum[i];

        if (series_sum == n) {
            equal_n++;
        }

        // pointers need to move towards each other
        if (series_sum < n) { // if the sum is less than n, increase j for a larger sum
            j++;
        } else {
            i++;
        }
    }

    cout << equal_n;

    return;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    closestPair();

    return 0;
}