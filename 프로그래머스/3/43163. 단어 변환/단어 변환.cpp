#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

unordered_map<string, bool> um;
vector<string> w;
int res = 100;

void dfs(string curr, string target, int count){   
    if(curr == target){
        if(res > count) res = count;
        return;
    }
    um[curr] = true;
    
    for(const auto ww : w){
        if(!um[ww]){
            int diff = 0;
            
            for(int i = 0; i < ww.size(); i++){
                if(curr[i] != ww[i]){
                    diff++;
                }
            }
            
            if(diff <= 1){
                dfs(ww, target, count + 1);
            }
        }
    }
    
    um[curr] = false;
}

int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    
    w = words;    
    dfs(begin, target, 0);    
    if(res == 100){
        answer = 0;   
    }
    else{
        answer = res;
    }
    
    return answer;
}