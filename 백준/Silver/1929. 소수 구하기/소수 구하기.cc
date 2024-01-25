#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

bool is_prime(long long x){
    if(x == 1 || x == 0) return false;
    if(x <= 3) return true;
    if(x % 2 == 0 || x % 3 == 0) return false;

    long long i = 5;
    while(i*i <= x){ //completes in O(sqrt(n))
        if(x % i == 0 || x % (i+2) == 0) return false;
        i++;
    }

    return true;
}

int main(){
    // cin, cout 속도 향상
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int m, n;
    cin >> m >> n;
    
    if(m == 1) m++;
    if(m == 2) cout << 2 << "\n";
    m += 1-m%2;
    for(int i = m; i <= n; i+=2){ 
        if(is_prime(i)){
            cout << i << "\n";
        }
    }

    return 0;
}

/** someone else's code that runs extremely fast
#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<iostream>
#include<vector>
#include<math.h>
using namespace std;
int a[1000001] = {0,};//1지워짐 0안지워짐
int main()
{
    int n,m;
    scanf("%d %d", &n, &m);
    a[1] = 1;
    for (int i = 2; i <= m; i++)
    {
        if (a[i] == 1)
        {
            continue;
        }
        for (int j = i*2; j <= m; j = j + i)
        {
            a[j] = 1;
        }
    }
    for (int i = n; i <= m; i++)
    {
        if (a[i] == 0)
        {
            printf("%d\n", i);
        }
    }
}
*/
