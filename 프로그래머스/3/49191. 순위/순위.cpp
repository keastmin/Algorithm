#include <iostream>
#include <string>
#include <vector>

using namespace std;

#define INF 987654321

int solution(int n, vector<vector<int>> results) {
    int answer = 0;
    vector<vector<int>> floyd(n + 1, vector<int>(n + 1, INF));
    
    for(int i = 1; i <= n; i++){
        floyd[i][i] = 0;
    } 
    
    for(const auto r : results){
        floyd[r[0]][r[1]] = 1;
    }
    
    for(int k = 1; k <= n; k++){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                if(floyd[i][k] + floyd[k][j] < floyd[i][j]){
                    floyd[i][j] = floyd[i][k] + floyd[k][j];
                }
            }
        }
    }
    
    for(int i = 1; i <= n; i++){
       bool check = true;
        for(int j = 1; j <= n; j++){
            if(i != j && floyd[i][j] == INF && floyd[j][i] == INF){
                check = false;
                break;
            }
        }
        if(check){
            answer++;
        }
    }
    
    return answer;
}