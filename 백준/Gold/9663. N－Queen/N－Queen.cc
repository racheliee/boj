#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

int col[16];
int n, num = 0;

void backTrack(int index){
    if(index == n) {
        num++;
    }else{
        for(int i = 0; i < n; i++){
            col[index] = i; //the row will be saved to the col
            bool flag = true;
            for(int j = 0; j < index; j++){
                if(col[index] == col[j] || abs(col[index] - col[j]) == index-j){ //same col or same diagonal
                    flag = false;
                    break;
                }
            }

            if(flag){
                backTrack(index+1);
            }
        }
    } 
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    backTrack(0);
    cout << num;

    return 0;
}