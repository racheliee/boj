#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

bool compare(const pair<string, int> a, const pair<string, int> b){
    if(a.second != b.second){ //num of occurences are different
        return a.second > b.second;
    }else if(a.first.length() != b.first.length()){ //length is different
        return a.first.length() > b.first.length();
    }else{
        return a.first < b.first;
    }
}

int main(){
    // cin, cout 속도 향상s
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m; 
    cin >> n >> m;

    unordered_map<string, int> vocab_map;

    string vocab;
    while(n){
        n--;
        
        cin >> vocab;

        if(vocab.length() >= m){
            vocab_map[vocab]++;
        }
    }

    vector<pair<string, int> > vocab_vector(vocab_map.begin(), vocab_map.end());
    sort(vocab_vector.begin(), vocab_vector.end(), compare);

    for(auto it = vocab_vector.begin(); it != vocab_vector.end(); ++it){
        cout << it->first << "\n";
    }
    
    return 0;
}