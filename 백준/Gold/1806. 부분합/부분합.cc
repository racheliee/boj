#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

int n;
long long s;
vector<long long> arr = {
    0,
};
vector<long long> sum = {
    0,
};

void closestPair() {
    cin >> n >> s;
    arr.resize(n);
    sum.resize(n + 1);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    partial_sum(arr.begin(), arr.end(), sum.begin() + 1); //+1 so the first element can be 0

    int min_num = INT_MAX;

    int i = 0;
    int j = 1;
    int series_sum;

    while (i < j && j < n+1) {
        series_sum = sum[j] - sum[i];

        if (series_sum >= s) {
            if (j - i < min_num) {
                min_num = j - i;
            }
        }

        // pointers need to move towards each other
        if (series_sum < s) { // if the sum is less than s, increase j for a larger sum
            j++;
        } else {
            i++;
        }
    }

    if(min_num == INT_MAX) cout << 0;
    else cout << min_num;

    return;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    closestPair();

    return 0;
}