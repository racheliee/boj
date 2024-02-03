#include <algorithm>
#include <cmath>
#include <deque>
#include <iostream>
#include <string.h>
#include <string>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int A, B, C;
    cin >> A >> B >> C;

    cout << (A+B)%C << "\n" << ((A%C)+(B%C))%C << "\n" <<  (A*B)%C << "\n" << ((A%C)*(B%C))%C;
}