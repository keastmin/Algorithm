#include <string>
#include <vector>

using namespace std;

long long solution(int n) {
    long long answer = 0;
    vector<long long> res (n + 1);
    
    if(n >= 1){
        res[1] = 1;
    }
    if(n >= 2){
        res[2] = 2;
    }
    for(int i = 3; i <= n; i++){
        res[i] = (res[i - 1] + res[i - 2]) % 1234567;
    }
    
    return res[n];
}