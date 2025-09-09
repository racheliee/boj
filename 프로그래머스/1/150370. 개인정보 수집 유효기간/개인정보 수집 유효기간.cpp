#include <string>
#include <vector>
#include <unordered_map>
#include <bits/stdc++.h>


using namespace std;

int dateToNum(string date, int months) {
    int y,m,d;
    char dot;
    stringstream ss(date);
    ss >> y >> dot >> m >> dot >> d;
    
    return y * (12 * 28) + m * 28 + d + months * 28;
}

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    vector<int> answer;
    
    unordered_map<string, int> t;
    
    for(const auto& s: terms) {
        stringstream ss(s);
        string term_type;
        int months;
        ss >> term_type >> months;
        t[term_type] = months;
    }
    
    string date, term_type;
    int len = (int)privacies.size();
    int tDate = dateToNum(today, 0);
    for(int i = 0; i < len; ++i) {
        stringstream ss(privacies[i]);
        ss >> date >> term_type;
        
        if(dateToNum(date, t[term_type]) <= tDate)
            answer.push_back(i+1);
    }
    
    return answer;
}