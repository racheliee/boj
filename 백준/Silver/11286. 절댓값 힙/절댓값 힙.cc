#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

int n;

struct Cmp{
    bool operator()(const pair<int, int> &a, const pair<int, int> &b) const {
        if(a.first == b.first)
            return a.second > b.second;
        return a.first > b.first;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    priority_queue<pair<int, int>, vector<pair<int, int>>, Cmp> pq;

    int temp;
    while (n--) {
        cin >> temp;
        if (temp != 0) {
            if (temp < 0)
                pq.push({abs(temp), -1});
            else
                pq.push({temp, 1});
        } else {
            if (pq.empty())
                cout << 0 << endl;
            else {
                cout << pq.top().first * pq.top().second << endl;
                pq.pop();
            }
        }
    }

    return 0;
}