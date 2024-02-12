#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

int n;
int min_v = INT_MAX;
int s[20][20];
int s_or_l[20] = {0,}; // s = 1, l = 0

void backTrack(int count, int index) {

    if (count == n / 2) {
        vector<int> start; //store indexes of start team
        vector<int> link; //store indexes of link team
        int s_score = 0;
        int l_score = 0;

        for (int i = 0; i < n; i++) {
            if (s_or_l[i]) {
                start.push_back(i);
            } else {
                link.push_back(i);
            }
        }

        for (int i = 0; i < n / 2; i++) {
            for (int j = 0; j < n / 2; j++) {
                s_score += s[start[i]][start[j]];
                l_score += s[link[i]][link[j]];
            }
        }

        if (abs(s_score - l_score) < min_v)
            min_v = abs(s_score - l_score);

        return;
    }

    for (int i = index; i < n; i++) {
        if (s_or_l[i])
            continue;
        else {
            s_or_l[i] = 1;
            backTrack(count + 1, i);
            s_or_l[i] = 0;
        }
    }

    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> s[i][j];
        }
    }

    backTrack(0, 0);
    cout << min_v;

    return 0;
}