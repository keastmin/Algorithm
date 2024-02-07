#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(int k, vector<int> score) {
    vector<int> answer;
    vector<int> tmp(k);
    int index = 0;
    for(int i = 0; i < score.size(); i++){
        if(index < k){
            tmp[index++] = score[i];
        }
        else {
            if(tmp[0] < score[i]){
                tmp[0] = score[i];
            }
        }
        sort(tmp.begin(), tmp.begin() + index);
        answer.push_back(tmp[0]);
    }
    return answer;
}