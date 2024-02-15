#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(string& a, string& b){
    return a + b > b + a;
}

string solution(vector<int> numbers) {
    string answer = "";
    vector<string> str(numbers.size());
    for(int i = 0; i < numbers.size(); i++){
        str[i] = to_string(numbers[i]);
    }
    sort(str.begin(), str.end(), cmp);
    
    if(str[0] == "0") answer = "0";
    else{
        for(const auto s : str){
            answer += s;
        }
    }
    
    return answer;
}