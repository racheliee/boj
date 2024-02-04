#include <algorithm>
#include <cmath>
#include <deque>
#include <iomanip>
#include <iostream>
#include <numeric>
#include <queue>
#include <string.h>
#include <string>
#include <vector>

using namespace std;

void print() {
    int n;
    cin >> n;

    long long int d[n - 1];
    long long int p[n - 1]; // last city's gas price will not be used

    for (int i = 0; i < n - 1; i++)
        cin >> d[i];
    for (int i = 0; i < n - 1; i++)
        cin >> p[i];

    int curr_p = p[0];
    int price = p[0]*d[0];
    for (int i = 1; i < n - 1; i++) {
        if (curr_p < p[i]) { //if current price is lower, keep current price
            price += curr_p * d[i];
        } else {  //encounter a lower price, use the new one.
            curr_p = p[i];
            price += p[i] * d[i];
        }
    }

    cout << price;

    return;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    print();

    return 0;
}