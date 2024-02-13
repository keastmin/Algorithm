#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int answer = 0;
    int wSize = want.size();
    int dSize = discount.size();
    unordered_map<string, int> backup;
    backup.insert({"apple", 1});
    
    for(int i = 0; i < wSize; i++){
        backup[want[i]] = number[i];
    }
    
    for(int i = 0; i <= dSize - 10; i++){
        unordered_map<string, int> um;
        um = backup;
        
        for(int j = i; j < i + 10; j++){
            if(um[discount[j]] > 0)
                um[discount[j]] -= 1;
        }
        
        bool check = false;
        for(const auto w : want){
            if(um[w] > 0){
                check = true;
            }
        }
        if(!check){
            answer++;
        }
    }
    
    return answer;
}