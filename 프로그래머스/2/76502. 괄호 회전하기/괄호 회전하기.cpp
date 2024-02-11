#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(string s) {
    int answer = 0;
    
    for(int i = 0; i < s.size() - 1; i++){
        stack<char> stk;
        for(const auto ss : s){
            if(ss == '[' || ss == '{' || ss == '(') stk.push(ss);
            else {
                if(stk.empty()){
                    answer--;
                    break;   
                }
                else{
                    char c = stk.top();
                    if(c == '[' && ss != ']') break;
                    else if(c == '{' && ss != '}') break;
                    else if(c == '(' && ss != ')') break;
                    stk.pop();
                }
            }
        }
        
        if(stk.empty()) answer++;
        
        string tmp = s.substr(0, 1);
        s.erase(0, 1);
        s += tmp;
    }
    
    return answer;
}