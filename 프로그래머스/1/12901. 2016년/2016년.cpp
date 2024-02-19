#include <iostream>
#include <string>
#include <vector>

using namespace std;

string solution(int a, int b) {
    //vector<int> day = {31, 29, 31, 30, 31, 30, 31, 31, 30, 29, 30, 31};
    vector<string> week = {"SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"};
    vector<int> start = {5, 1, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4};
    
    return week[(start[a - 1] + (b - 1)) % 7];
}