#include <iostream>
#include <algorithm>
#include <string>
#include <set>
#include <iomanip>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    double x, y;
    cin >> x >> y;

    cout << setprecision(30);
    cout << x/y;

    return 0;
}