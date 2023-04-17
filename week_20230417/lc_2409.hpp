#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    const int month[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    int sum(const string& time) {
        int m = stoi(time.substr(0, 2));
        int d = stoi(time.substr(3, 2));
        int ans = 0;
        for(int i = 1; i < m; ++i){
            ans += month[i-1];
        }
        return ans + d;
    }

    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        int a1 = sum(arriveAlice);
        int a2 = sum(leaveAlice);
        int b1 = sum(arriveBob);
        int b2 = sum(leaveBob);
        int ans = 0;
        if(b1 <= a2 && b2 >= a1){
            ans = min(a2, b2) - max(a1, b1) + 1;
        }
        return ans;
    }
};