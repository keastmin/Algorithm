#include <string>
#include <vector>

using namespace std;

string solution(vector<string> cards1, vector<string> cards2, vector<string> goal) {   
    int idx1 = -1;
    int idx2 = -1;
    
    vector<bool> check1(cards1.size(), false);
    vector<bool> check2(cards2.size(), false);
    for(const auto g : goal){
        for(int i = 0; i < cards1.size(); i++){
            if(g == cards1[i] && !check1[i]){
                if(i - idx1 == 1){
                    idx1 = i;
                    check1[i] = true;
                    break;
                }
                else{
                    return "No";
                }
            }
        }
        
        for(int i = 0; i < cards2.size(); i++){
            if(g == cards2[i] && !check2[i]){
                if(i - idx2 == 1){
                    idx2 = i;
                    check2[i] = true;
                    break;
                }
                else{
                    return "No";
                }
            }
        }
    }
    
    return "Yes";
}