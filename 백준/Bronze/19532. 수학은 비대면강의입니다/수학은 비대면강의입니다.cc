#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main(){
    // cin, cout 속도 향상
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int a, b, c, d, e, f;
    scanf("%d %d %d %d %d %d", &a, &b, &c, &d, &e, &f);

    for(int x = -999; x <= 999; x++){
        for(int y = -999; y <= 999; y++){
            if(a*x + b*y == c && d*x + e*y == f){
                cout << x << " " << y;
                break;
            }
        }
    }
    
    return 0;
}