#include <iostream>
#include <algorithm>
#include <string>
#include <unordered_map>

using namespace std;

int main(){
    // cin, cout 속도 향상
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    // map보다 더 빠른 탐색을 하기 위한 자료구조
    // unordered_map은 해쉬테이블로 구현한 자료구조로 탐색 시간복잡도는 O(1)
    unordered_map<string, int> pokemon_str;
    unordered_map<int, string> pokemon_int;

    for(int i = 0; i < n; i++){
        string name;
        cin >> name;
        pokemon_str[name] = i+1;
        pokemon_int[i] = name;
    }

    string instr;
    for(int i = 0; i < m; i++){
        cin >> instr;

        //check if instruction is all digits
        if(!instr.empty() && all_of(instr.begin(), instr.end(), ::isdigit)){
            cout << pokemon_int[stoi(instr)-1] << "\n";
        }else{
            cout << pokemon_str[instr] << "\n";
        }
    }

    return 0;
}