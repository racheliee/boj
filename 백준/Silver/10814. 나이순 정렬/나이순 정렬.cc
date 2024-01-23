#include <iostream>
#include <algorithm>
#include <string>
#include <tuple>

using namespace std;

bool compare(const tuple<int, string, int>& a, const tuple<int, string, int>& b){
    if(get<0>(a) != get<0>(b)){
        return get<0>(a) < get<0>(b);
    }else{
        return get<2>(a) < get<2>(b); //compare based on registration date
    }

}
int main(){
    // cin, cout 속도 향상
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    // tuple supports an arbiraty amount of types stores
    // std::get<n>(tuple) --> retrive the nth element
    vector<tuple<int, string, int> > members(n);

    for(int i = 0; i < n; i++){
        int age;
        cin >> age;
        string name;
        cin >> name;

        members[i] = tuple<int, string, int>(age, name, i);
    }

    sort(members.begin(), members.end(), compare);

    for(int i = 0; i < n; i++){
        cout << get<0>(members[i]) << " " << get<1>(members[i]) << "\n";
    }

    return 0;
}