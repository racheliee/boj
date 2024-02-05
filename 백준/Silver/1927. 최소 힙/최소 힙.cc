#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

int n;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    priority_queue<int, vector<int>, greater<int>> pq;

    int temp;
    while (n--) {
        cin >> temp;
        if (temp)
            pq.push(temp);
        else {
            if (pq.empty())
                cout << 0 << endl;
            else {
                cout << pq.top() << endl;
                pq.pop();
            }
        }
    }

    return 0;
}