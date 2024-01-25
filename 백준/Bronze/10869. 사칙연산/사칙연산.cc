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

    int x, y;
    cin >> x >> y;

    cout << x+y << "\n" << x-y << "\n" << x*y << "\n" << x/y << "\n" << x%y << "\n" ;


    return 0;
}