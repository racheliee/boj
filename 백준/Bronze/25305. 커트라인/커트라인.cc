#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main(){
    // cin, cout 속도 향상
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n; //num of test takers
    int k; //num of awards
    scanf("%d %d", &n, &k);

    int test_scores[n];
    for(int i = 0; i < n; i++){
        scanf("%d", &test_scores[i]);
    }

    sort(test_scores, test_scores+n, greater<int>()); //내림차순 정렬

    cout << test_scores[k-1];

    return 0;
}