#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main(){
    // cin, cout 속도 향상
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    scanf("%d %d", &n, &m);

    char board[n][m];
    for(int i = 0; i < n; i++){
        scanf("%s", board[i]);
    }

    int min = 999999;

    for(int i = 0; i < n-7; i++){
        for(int j = 0; j < m-7; j++){
            int UL_white = 0;
            int UL_black = 0;

            for(int row = i; row < i+8; row++){
                for(int col = j; col < j+8; col++){
                    if((row + col) % 2 == 0){
                        //upper left is white
                        if(board[row][col] == 'W'){
                            UL_white++;
                        }else{
                            UL_black++;
                        }
                    }else{
                        if(board[row][col] == 'B'){
                            UL_white++;
                        }else{
                            UL_black++;
                        }
                    }
                }
            }
            
            min = UL_white < min? UL_white: min;
            min = UL_black < min? UL_black: min;
        }
    }

    cout << min;

    return 0;
}