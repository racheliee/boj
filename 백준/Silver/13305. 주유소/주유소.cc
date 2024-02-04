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

    int d[n - 1];
    int p[n - 1]; // last city's gas price will not be used

    for (int i = 0; i < n - 1; i++)
        cin >> d[i];
    for (int i = 0; i < n - 1; i++)
        cin >> p[i];

    int *min_price = min_element(p, p + n - 1);
    int price = 0;
    for (int i = 0; i < n - 1; i++) {
        if (p[i] == *min_price) {
            price += p[i] * accumulate(d + i, d + n - 1, 0);
            break;
        } else {
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