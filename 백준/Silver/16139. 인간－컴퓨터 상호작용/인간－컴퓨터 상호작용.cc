#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

string str;
int q, l, r, sum;
int alphabet[26][200001] = {
    0,
};
char a;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> str >> q;

    alphabet[str[0] - 97][0] = 1;
    for (int i = 1; i < str.length(); i++) {
        for (int j = 0; j < 26; j++) {
            if (str[i] - 97 == j) {
                alphabet[j][i] = alphabet[j][i - 1] + 1;
            } else {
                alphabet[j][i] = alphabet[j][i - 1];
            }
        }
    }

    while (q--) {
        cin >> a >> l >> r;
        sum = alphabet[a - 97][r] - alphabet[a - 97][l - 1];
        if (sum < 0)
            cout << 0 << endl;
        else
            cout << sum << endl;
    }

    return 0;
}