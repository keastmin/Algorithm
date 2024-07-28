#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<string> friends, vector<string> gifts) {
    int answer = 0;
    
    // 선물 지수와 선물 교환 횟수 변수 선언
    const int friendsCnt = friends.size();
    vector<int> giftPoint(friendsCnt, 0);
    vector<vector<int>> giftCount(friendsCnt, vector<int>(friendsCnt, 0));
    vector<int> res(friendsCnt, 0);
    
    // 이름을 int형 인덱스로 변환
    unordered_map<string, int> idx;    
    for(int i = 0; i < friendsCnt; i++){
        idx[friends[i]] = i;
    }

    // 선물 지수와 선물 교환 횟수 계산 및 저장
    for(string g : gifts){
        size_t space_pos = g.find(' ');
        string from, to;
        
        if(space_pos != string::npos){
            from = g.substr(0, space_pos);
            to = g.substr(space_pos + 1);
            
            giftPoint[idx[from]]++;
            giftPoint[idx[to]]--;
            
            giftCount[idx[from]][idx[to]]++;
        }
    }
    
    // 선물을 많이 받을 사람 계산
    for(int i = 0; i < friendsCnt - 1; i++){
        for(int j = i + 1; j < friendsCnt; j++){
                int iCnt = giftCount[i][j];
                int jCnt = giftCount[j][i];
                
                if(iCnt > jCnt){ 
                    res[i]++;               
                } 
                else if(iCnt < jCnt){ 
                    res[j]++;
                }
                else if(iCnt == jCnt){
                    if(giftPoint[i] > giftPoint[j]){ 
                        res[i]++;
                    }
                    else if(giftPoint[i] < giftPoint[j]){ 
                        res[j]++;
                    }                                                        
                }
            
        }
    }
    
    for(int i = 0; i < friendsCnt; i++){
        answer = max(answer, res[i]);
    }
    
    return answer;
}